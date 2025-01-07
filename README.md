# Hibiscus-Sense-with-FAVORIOT
This project utilizes the Hibiscus Sense development board to demonstrate IoT data transmission to the FAVORIOT platform using multiple communication protocols, including HTTP, MQTT, CoAP, and WebSocket. The Hibiscus Sense comes equipped with a range of sensors and actuators that make it an ideal choice for showcasing diverse IoT functionalities.

**Sensors Used**:
  * APDS9960: Captures proximity, RGB light, and gesture data.
  * BME280: Measures altitude, barometric pressure, humidity, and temperature.
  * MPU6050: Provides motion tracking with 3-axis gravitational acceleration, 3-axis rotational velocity, and temperature readings.

**Actuators Used**:
  * Buzzer: Used for sound notifications and alerts.
  * Blue LED: Offers basic visual feedback.
  * WS2812 RGB LED: Displays multicolor feedback for visual status indications.

**Project Highlights**:
  * Sensor data is transmitted to FAVORIOT using multiple protocols, demonstrating the flexibility of IoT communication.
  * The actuators are controlled via commands sent from the FAVORIOT platform, showcasing bidirectional interaction.
  * The project highlights how diverse data types from the sensors can be seamlessly integrated into FAVORIOT's ecosystem.

By combining the capabilities of the Hibiscus Sense board with FAVORIOT’s IoT platform, this project emphasizes the practical implementation of IoT communication protocols and real-time data exchange.

<p align="center"><img src="https://github.com/XK-Frost01/Hibiscus-Sense-with-FAVORIOT/blob/main/Reference/PROJECT%20SETUP.png" width="900"></p>
<br>

## Project Setup

### Step 1: Install Arduino IDE

 * To install Arduino IDE, you can go to [Arduino official website](https://www.arduino.cc/en/software)

```URL
https://www.arduino.cc/en/software
```

<p align="center"><img src="https://github.com/XK-Frost01/Hibiscus-Sense-with-FAVORIOT/blob/main/Reference/Arduino%20IDE_1.png" width="900"></p>
<p align="center"><img src="https://github.com/XK-Frost01/Hibiscus-Sense-with-FAVORIOT/blob/main/Reference/Arduino%20IDE_2.png" width="900"></p>
<p align="center"><img src="https://github.com/XK-Frost01/Hibiscus-Sense-with-FAVORIOT/blob/main/Reference/Arduino%20IDE_3.png" width="900"></p>
<p align="center"><img src="https://github.com/XK-Frost01/Hibiscus-Sense-with-FAVORIOT/blob/main/Reference/Arduino%20IDE_5.png" width="900"></p>
<br><br>

### Step 2: CP210x unversal driver

 * After downloading the Arduino IDE, you need to install [universal driver](https://www.silabs.com/developer-tools/usb-to-uart-bridge-vcp-drivers?tab=downloads)

```URL
https://www.silabs.com/developer-tools/usb-to-uart-bridge-vcp-drivers?tab=downloads
```

<p align="center"><img src="https://github.com/XK-Frost01/Hibiscus-Sense-with-FAVORIOT/blob/main/Reference/Arduino%20IDE_10.png" width="900"></p>
<p align="center"><img src="https://github.com/XK-Frost01/Hibiscus-Sense-with-FAVORIOT/blob/main/Reference/Arduino%20IDE_11.png" width="900"></p>
<p align="center"><img src="https://github.com/XK-Frost01/Hibiscus-Sense-with-FAVORIOT/blob/main/Reference/Arduino%20IDE_12.png" width="900"></p>
<br><br>

### Step 3: Library setup

 * After that, you can open Arduino IDE application
 * go to file > preference
 * and insert the addition URL referece for ESP32:

```URL
https://espressif.github.io/arduino-esp32/package_esp32_index.json
```

<p align="center"><img src="https://github.com/XK-Frost01/Hibiscus-Sense-with-FAVORIOT/blob/main/Reference/Arduino%20IDE_6.png" width="900"></p>
<p align="center"><img src="https://github.com/XK-Frost01/Hibiscus-Sense-with-FAVORIOT/blob/main/Reference/Arduino%20IDE_7.png" width="900"></p>
<p align="center"><img src="https://github.com/XK-Frost01/Hibiscus-Sense-with-FAVORIOT/blob/main/Reference/Arduino%20IDE_15.png" width="900"></p>
<br>

 * then you can go to the **board manager** >  and type:
   * **ESP32**

<p align="center"><img src="https://github.com/XK-Frost01/Hibiscus-Sense-with-FAVORIOT/blob/main/Reference/Arduino%20IDE_8.png" width="900"></p>

> Make sure it ESP32 by ESPRESSIF
<br>

 * after that you can go to the **library manager** > and type as the folowing:
    * **Adafruit BME280**
    * **Adafruit APDS9960**
    * **Adafruit MPU6050**
    * **Adafruit NeoPixel**
    * **MQTT**

<p align="center"><img src="https://github.com/XK-Frost01/Hibiscus-Sense-with-FAVORIOT/blob/main/Reference/Arduino%20IDE_9.png" width="900"></p>

>  make sure the Adafruit library is by Adafruit and MQTT library is by Joel Gaehwiler
<br><br>

### Step 4: Plug in Hibisus Sense

 * plug in the hibiscus sense to your laptop

<p align="center"><img src="https://github.com/XK-Frost01/Hibiscus-Sense-with-FAVORIOT/blob/main/Reference/Hibiscus%20Sense%20plug%20in.jpeg" width="900"></p>

 * then, you can go to the Device Manager > Ports (COM & LPT)
 * search for CP210x driver will connected to which COM

<p align="center"><img src="https://github.com/XK-Frost01/Hibiscus-Sense-with-FAVORIOT/blob/main/Reference/Arduino%20IDE_13.png" width="900"></p>

 * and lastly you can connect to board and the port as below

<p align="center"><img src="https://github.com/XK-Frost01/Hibiscus-Sense-with-FAVORIOT/blob/main/Reference/Arduino%20IDE_14.png" width="900"></p>
<br><br>

### Step 5: Setup Favoriot Platform

 * This project integrate the use if ESP32 sensor with [FAVORIOT platform](https://platform.favoriot.com/login)
 * to open favoriot platform, you can search:

```URL
https://platform.favoriot.com/login
```

<p align="center"><img src="https://github.com/XK-Frost01/Hibiscus-Sense-with-FAVORIOT/blob/main/Reference/FAVORIOT_1.png" width="900"></p>

 * For a beginner-friendly tutorial on getting started with the FAVORIOT platform and creating a device for your project, refer to the link provided below:

```URL
https://www.youtube.com/playlist?list=PLeB7L9fw2CnIrfLRYK42tPN2LJohwfGtu
```

> You can go through video 1 to 5 and decide on how to setup your project in FAVORIOT platform

 * or you can refer to FAVORIOT recources tab:

<p align="center"><img src="https://github.com/XK-Frost01/Hibiscus-Sense-with-FAVORIOT/blob/main/Reference/FAVORIOT_2.png" width="900"></p>
<p align="center"><img src="https://github.com/XK-Frost01/Hibiscus-Sense-with-FAVORIOT/blob/main/Reference/FAVORIOT_3.png" width="900"></p>
<br><br>

### Step 6: uploading the code inside ESP32

 * After finish creating device inside FAVORIOT platform, you can select the code from the folder above which contains examples for four protocols: 
    * HTTPS
    * MQTTS
    * CoAP
    * WebSocket.
 * After copying the code into the Arduino IDE, you can upload it.

<p align="center"><img src="https://github.com/XK-Frost01/Hibiscus-Sense-with-FAVORIOT/blob/main/Reference/Arduino%20IDE_16.png" width="900"></p>

 * then you can refer favoriot data stream to see if there is data entering

<p align="center"><img src="https://github.com/XK-Frost01/Hibiscus-Sense-with-FAVORIOT/blob/main/Reference/FAVORIOT_6.png" width="900"></p>
<br><br>

### Step 7:  Setup FAVORIOT dashboard   

 * You can display the data received in the FAVORIOT Data Stream on the FAVORIOT Dashboard; for guidance on dashboard setup, refer to the link below.
    * [FAVORIOT TUTORIAL: HIBISCUS SENSE DASHBOARD SETUP (Part 1)](https://youtu.be/JYTBMOHCwtE)
    * [FAVORIOT TUTORIAL: HIBISCUS SENSE DASHBOARD SETUP (Part 2)](https://youtu.be/THDEmfXA9zQ)
