#include <WiFi.h>
#include <MQTT.h>
#include <NetworkClientSecure.h>
#include <Adafruit_APDS9960.h>
#include <Adafruit_BME280.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_NeoPixel.h>
#include "tones.h"
#include "FavoriotCA_MQTT.h"

const char ssid[] = "YOUR_WIFI_SSID";
const char password[] = "YOUR_WIFI_PASSWORD";
const char deviceDeveloperID[] = "YOUR_DEVICE_DEVELOPER_ID";
const char deviceAccessToken[] = "YOUR_DEVICE_ACCESS_TOKEN";
const char publishTopic[] = "/v2/streams";
const char statusTopic[] = "/v2/streams/status";
const char rpcTopic[] = "/v2/rpc";  // To Get data from dashboard
const char* clientID = "@XK-ESP32-HS";

Adafruit_NeoPixel rgb(1, 16);
Adafruit_APDS9960 apds;
Adafruit_BME280 bme;
Adafruit_MPU6050 mpu;
sensors_event_t a, g, temp;

long previousMillis = 0;
String buzzer, State, ReceiveResponse;
int r = 0, gr = 0, b = 0;
NetworkClientSecure client;
MQTTClient mqtt(4096);

void connectToWiFi();
void connectToFavoriotMQTT();
void SendData();
void GetData();

void connectToWiFi() {        // for easier calling in the loop
  Serial.print("Connecting to Wi-Fi '" + String(ssid) + "' ...");
  WiFi.begin(ssid, password);
  while(WiFi.status() != WL_CONNECTED){
    Serial.println("...");
    delay (250);
  }
  Serial.println(" connected!");
}
void connectToFavoriotMQTT() {    
  Serial.print("Connecting to Favoriot MQTT ...");
  client.setCACert(FavoriotCA_MQTT);
  mqtt.begin("mqtt.favoriot.com", 8883, client);
  mqtt.onMessage(GetData);

  while (!mqtt.connect(clientID, deviceAccessToken, deviceAccessToken)) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("");
  Serial.println(" connected!");
  // subscribe rpc topic
  Serial.println("Subscribe to: " + String(deviceAccessToken) + String(rpcTopic));
  mqtt.subscribe(String(deviceAccessToken) + String(rpcTopic));
  //subscribe publish status
  Serial.println("Subscribe to: " + String(deviceAccessToken) + String(statusTopic));
  mqtt.subscribe(String(deviceAccessToken) + String(statusTopic));
  Serial.println();
}
void setup(){
  Serial.begin (115200);
  pinMode(2,OUTPUT); 
  digitalWrite(2, HIGH);
  if (!apds.begin() || !bme.begin() || !mpu.begin()){
    Serial.println("Not detecting the Hibiscus Sense sensor");
  }   
  apds.enableProximity(true);  
  rgb.begin();
  connectToWiFi();
  connectToFavoriotMQTT();
}
void loop() {
  // Check Wi-Fi connection
  if (WiFi.status() != WL_CONNECTED) {
    connectToWiFi();
  }
  // Check MQTT connection
  if (!mqtt.connected()) {
    connectToFavoriotMQTT();
  }

  mqtt.loop();
  delay(10);  // <- fixes some issues with WiFi stability
  SendData();
  delay(250);
}

void GetData(String &topic, String &ReceiveResponse) {
  Serial.println("Message received on topic: " + topic);
  Serial.println("Payload: " + ReceiveResponse);

  if (ReceiveResponse.indexOf("\BUZZER\":\"ON\"") >= 0){
    buzzer = "ON";
    Serial.println("Buzzzer turned ON");
  } else if (ReceiveResponse.indexOf("\"BUZZER\":\"OFF\"") >= 0){
    buzzer = "OFF";
    Serial.println("Buzzer turned OFF");
  }

  if (buzzer == "ON"){
    if (ReceiveResponse.indexOf("\"SONG_1\":\"ON\"") >= 0){
      song1();
    } else if (ReceiveResponse.indexOf("\"SONG_2\":\"ON\"") >= 0){
      song2();
    }
  }

  if (ReceiveResponse.indexOf("\"LED\":\"ON\"") >= 0) {
    digitalWrite(2, LOW);
    Serial.println("LED turned ON");
  } else if(ReceiveResponse.indexOf("\"LED\":\"OFF\"") >= 0){
    digitalWrite(2, HIGH);
    Serial.println("LED turned OFF");
  }

  if (ReceiveResponse.indexOf("\"RGB\":\"ON\"") >= 0) {
    State = "ON";
    Serial.println("RGB turned ON");
  } else if(ReceiveResponse.indexOf("\"RGB\":\"OFF\"") >= 0){
    State = "OFF";
    Serial.println("RGB turned OFF");
  } else if (ReceiveResponse.indexOf("\"RGB_Red\":") != -1) {
    r = extractValue(ReceiveResponse, "\"RGB_Red\":");
  } else if (ReceiveResponse.indexOf("\"RGB_Green\":") != -1) { 
    gr = extractValue(ReceiveResponse, "\"RGB_Green\":"); 
  } else if (ReceiveResponse.indexOf("\"RGB_Blue\":") != -1) { 
    b = extractValue(ReceiveResponse, "\"RGB_Blue\":"); 
  }
  Serial.println("Extracted Values:");
  Serial.println("Red: " + String(r));
  Serial.println("Green: " + String(gr));
  Serial.println("Blue: " + String(b));
  
  if(State == "ON"){
    rgb.setPixelColor(0, r, gr, b);  // Update RGB color
  } else {
    rgb.setPixelColor(0, 0, 0, 0);  // Turn off RGB when OFF
  }
  rgb.show();  // Apply changes
}

int extractValue(String payload, String key) {
  int startIndex = payload.indexOf(key) + key.length();
  int endIndex = payload.indexOf(",", startIndex);
  if (endIndex == -1) {
    endIndex = payload.indexOf("}", startIndex);  // Handle last item case
  }
  String value = payload.substring(startIndex, endIndex);
  value.trim(); 
  value.replace("\"", ""); 
  Serial.println("Extracted value for " + key + ": " + value);  // Debug value extraction

  return value.toInt(); 
}
void song1(){
  tone(13, NOTE_D4);  // buzzer will sound according to NOTE_D4.
  delay(500);
  noTone(13);  // buzzer has no sound since PWM signal is 0.
  delay(500);
}
void song2(){
  tone(13, NOTE_D5);  // buzzer will sound according to NOTE_D5.
  delay(500);
  noTone(13);  // buzzer has no sound since PWM signal is 0.
  delay(500);
}
void SendData(){
  if(millis() - previousMillis > 15000){
    previousMillis = millis();

    Serial.print("Proximity: ");
    Serial.println(apds.readProximity());

    Serial.print("Relative Humidity: ");
    Serial.print(bme.readHumidity());
    Serial.println(" %RH");

    Serial.print("Approx. Altitude: ");
    Serial.print(bme.readAltitude(1013.25));
    Serial.println(" m");

    Serial.print("Barometric Pressure: ");
    Serial.print(bme.readPressure());
    Serial.println(" Pa");

    Serial.print("Ambient Temperature: ");
    Serial.print(bme.readTemperature());
    Serial.println(" °C");

    String json = "{\"device_developer_id\":\"" + String(deviceDeveloperID) + "\",\"data\":{";
    
    json += "\"proximity\":\"" + String(apds.readProximity()) + "\",";
    json += "\"humidity\":\"" + String(bme.readHumidity()) + "\",";
    json += "\"altitude\":\"" + String(bme.readAltitude(1013.25)) + "\",";
    json += "\"barometer\":\"" + String(bme.readPressure()/100.00) + "\",";
    json += "\"temperature\":\"" + String(bme.readTemperature()) + "\",";
    
    mpu.getEvent(&a,&g,&temp);
    
    Serial.print("Acceleration X:");
    Serial.print(a.acceleration.x);
    Serial.print(", Y:");
    Serial.print(a.acceleration.y);
    Serial.print(", Z:");
    Serial.print(a.acceleration.z);
    Serial.println(" m/s^2");

    Serial.print("Rotation X:");
    Serial.print(g.gyro.x);
    Serial.print(", Y:");
    Serial.print(g.gyro.y);
    Serial.print(", Z:");
    Serial.print(g.gyro.z);
    Serial.println(" rad/s");

    json += "\"accx\":\"" + String(a.acceleration.x) + "\",";
    json += "\"accy\":\"" + String(a.acceleration.y) + "\",";
    json += "\"accz\":\"" + String(a.acceleration.z) + "\",";
    json += "\"gyrox\":\"" + String(g.gyro.x) + "\",";
    json += "\"gyroy\":\"" + String(g.gyro.y) + "\",";
    json += "\"gyroz\":\"" + String(g.gyro.z) + "\"";
    
    json += "}}";

    Serial.println("\nSending data to Favoriot's Data Stream ...");
    Serial.println("Data to Publish: " + json);
    Serial.println("Publish to: " + String(deviceAccessToken) + String(publishTopic));
    // Publish to /v2/streams
    mqtt.publish(String(deviceAccessToken) + String(publishTopic), json);
  }
}