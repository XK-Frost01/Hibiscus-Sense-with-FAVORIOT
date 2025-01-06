# Hibiscus-Sense-with-FAVORIOT
Exploring data transmission from Arduino-based ESP32 devices to the Favoriot platform using multiple protocols, including HTTP, MQTT, CoAP, and WebSocket. The focus is on showcasing diverse communication methods for IoT integration with Favoriot.

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

<p align="center"><img src="https://github.com/XK-Frost01/Hibiscus-Sense-with-FAVORIOT/blob/main/Reference/Arduino%20IDE_9.png" width="900"><</p>

>  make sure the Adafruit library is by Adafruit and MQTT library is by Joel Gaehwiler
<br>

Step 4: Plug in Hibisus Sense

 * plug in the hibiscus sense to your laptop
<p align="center"><img src="https://github.com/XK-Frost01/Hibiscus-Sense-with-FAVORIOT/blob/main/Reference/Arduino%20IDE_9.png" width="900"><</p>

 * then, you can go to the Device Manager > Ports (COM & LPT)
 * you can plug in your device to your laptop and search for CP210x driver will connected to which COM

<p align="center"><img src="https://github.com/XK-Frost01/Hibiscus-Sense-with-FAVORIOT/blob/main/Reference/Arduino%20IDE_13.png" width="900"></p>

 * and lastly you can connect to board and the port as below

<p align="center"><img src="https://github.com/XK-Frost01/Hibiscus-Sense-with-FAVORIOT/blob/main/Reference/Arduino%20IDE_14.png" width="900"></p>

Step 4: Setup Favoriot Platform
 * This project integrate the use if ESP32 sensor with [FAVORIOT platform](https://platform.favoriot.com/login)
 * to open favoriot platform, you can search:

```URL
https://platform.favoriot.com/login
```
<p align="center"><img src="https://github.com/XK-Frost01/Hibiscus-Sense-with-FAVORIOT/blob/main/Reference/Arduino%20IDE_14.png" width="900"></p>

 * then, to start using the favoriot.
 * To learn on how to create a new hierarchy or device you can follow copy the link below

<p align="center"><img src="https://github.com/XK-Frost01/Hibiscus-Sense-with-FAVORIOT/blob/main/Reference/Arduino%20IDE_14.png" width="900"></p>
```URL
https://www.youtube.com/watch?v=V8E6XRoVRUg&list=PLeB7L9fw2CnIrfLRYK42tPN2LJohwfGtu&index=1
```
<p align="center"><img src="https://github.com/XK-Frost01/Hibiscus-Sense-with-FAVORIOT/blob/main/Reference/Arduino%20IDE_14.png" width="900"></p>
```URL
https://www.youtube.com/watch?v=okdeDkr2ps4&list=PLeB7L9fw2CnIrfLRYK42tPN2LJohwfGtu&index=2
```
```URL
https://www.youtube.com/watch?v=YMns-S28X3k&list=PLeB7L9fw2CnIrfLRYK42tPN2LJohwfGtu&index=3
```
```URL
https://www.youtube.com/watch?v=mNw0p_OE6OY&list=PLeB7L9fw2CnIrfLRYK42tPN2LJohwfGtu&index=4
```
```URL
https://www.youtube.com/watch?v=490DgUlIHN8&list=PLeB7L9fw2CnIrfLRYK42tPN2LJohwfGtu&index=5
```

Step 5: uploading the code inside ESP32


Step6:  Setup FAVORIOT dashboard       
 * [FAVORIOT TUTORIAL: HIBISCUS SENSE DASHBOARD SETUP (Part 1)](https://youtu.be/JYTBMOHCwtE)
 * [FAVORIOT TUTORIAL: HIBISCUS SENSE DASHBOARD SETUP (Part 2)](https://youtu.be/THDEmfXA9zQ)
