# Hibiscus-Sense-with-FAVORIOT
Exploring data transmission from Arduino-based ESP32 devices to the Favoriot platform using multiple protocols, including HTTP, MQTT, CoAP, and WebSocket. The focus is on showcasing diverse communication methods for IoT integration with Favoriot.

<p align="center"><img src="https://github.com/myduino/Hibiscus-Sense-Arduino/blob/main/references/hibiscus-sense.png" width="400"></p>

## Introduction to ESP32

In this project, the ESP32 that will be used is Hibiscus Sense. Hibiscus Sense is a versatile Internet of Things (IoT) development board, powered by the mighty and popular dual-core ESP32 microcontroller. This device is equipped with 3 type of actuator and 3 type of sensor which is:  
- 3 sensors:
  - **APDS9960**: an environment sensor, which sense *proximity, RGB* and *gesture*.
  - **BME280**: an environment sensor, which sense the *altitude, barometric pressure, humidity* and *temperature*.
  - **MPU6050**: 6-axis motion tracking sensor, which sense *3-axis gravitational acceleration, 3-axis rotational velocity* and *temperature*.
- 3 actuators:
  - **Buzzer**: short distance small buzzer.
  - **LED**: blue LED.
  - **RGB LED**: WS2812 RGB LED.
