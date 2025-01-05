# Hibiscus-Sense-with-FAVORIOT
Exploring data transmission from Arduino-based ESP32 devices to the Favoriot platform using multiple protocols, including HTTP, MQTT, CoAP, and WebSocket. The focus is on showcasing diverse communication methods for IoT integration with Favoriot.

<p align="center"><img src="https://github.com/XK-Frost01/Hibiscus-Sense-with-FAVORIOT/blob/main/Reference/hibiscus-sense.png" width="400"></p>

## Introduction to ESP32

In this project, the ESP32 that will be used is [Hibiscus Sense](https://myduino.com/product/myd-036/). [Hibiscus Sense](https://myduino.com/product/myd-036/) is a versatile Internet of Things (IoT) development board, powered by the mighty and popular dual-core [ESP32](https://www.espressif.com/en/products/socs/esp32) microcontroller. This device is equipped with 3 type of actuator and 3 type of sensor which is:  
* 3 sensors:
  * **APDS9960**: an environment sensor, which sense *proximity, RGB* and *gesture*.
  * **BME280**: an environment sensor, which sense the *altitude, barometric pressure, humidity* and *temperature*.
  * **MPU6050**: 6-axis motion tracking sensor, which sense *3-axis gravitational acceleration, 3-axis rotational velocity* and *temperature*.

* 3 actuators:
  * **Buzzer**: short distance small buzzer.
  * **LED**: blue LED.
  * **RGB LED**: WS2812 RGB LED.

Hibiscus Sense comes with **USB Type-C** to power up the board and to program the ESP32. The on-board USB-to-Serial converter (**Silicon Labs CP2104**) with **automatic bootloader reset** circuit, eliminating the need to press the RESET button each time you upload a program.

## Hibiscus Sense Features

<p align="center"><img src="https://github.com/myduino/Hibiscus-Sense-Arduino/raw/main/references/hibiscus-sense-features.png" width="900"></a></p>

## Hibiscus Sense Pinout Diagram

<p align="center"><img src="https://github.com/myduino/Hibiscus-Sense-Arduino/raw/main/references/hibiscus-sense-pinout.png" width="900"></a></p>

* **Blue LED** is connected to ESP32's **`GPIO2`**.
* **Small Buzzer** is connected to ESP32's **`GPIO13`**.
* **WS2812 RGB LED** is connected to ESP32's **`GPIO16`**.
* All GPIOs can be configured as digital output, PWM output or digital input, except **`GPIO34, GPIO35, GPIO36, GPIO39`** cannot be configured as output. These digital GPIOs can be configured with internal pull-up or pull-down.
* Has two 12-bit ADCs with selectable ranges of 0-1V, 0-1.4V, 0-2V, or 0-4V, on 15 channels (analog-enabled pins) seperated as **`ADC1`** pins and **`ADC2`** pins. _**Note**: Avoid using ADC2 pins, when using Wi-Fi, consider using the ADC1 pins instead_.
* ESP32's `VSPI` is complete **MISO** **`GPIO19`**, **MOSI** **`GPIO32`**, **CLK** **`GPIO18`** and **CS** **`GPIO5`**.
* ESP32's `I2C` **SDA** **`GPIO21`** and **SCL** **`GPIO22`**, without pullup resistor.
* **Sensors**: **APDS9960**, **BME280** and **MPU6050** interfaced to the ESP32's `I2C`, respective I2C address: **`0x39`**, **`0x77`** and **`0x68`**.
* Each GPIO absolute maximum current drawn only 40mA.
* Board measurement including header in mm: 58.7 x 27 x 13.3 (length x width x height).
* Package measurement in mm: 71.8 x 35.5 x 20.4 (length x width x height).


## Project Setup

The material i use in this project is: 
1. Arduino
2. Favoriot Platform
3. Hibiscus Sense (ESP32)

### Installing the Arduino IDE
  
