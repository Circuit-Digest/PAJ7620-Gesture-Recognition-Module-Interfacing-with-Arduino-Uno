# PAJ7620 Gesture Recognition Module with Arduino 🚀

This repository contains code to interface the PAJ7620 Gesture Recognition module with an Arduino. The code also demonstrates how to display detected gestures on a 16x2 I2C LCD.

## Features ✨
- Detects multiple gestures such as left, right, up, down, forward, backward, clockwise, and anti-clockwise movements.
- Displays gesture icons and descriptions on an LCD screen.
- Uses the DFRobot_PAJ7620U2 library for gesture recognition.

## Hardware Required 🔧
- Arduino board (e.g., Uno, Mega)
- PAJ7620 Gesture Recognition module
- 16x2 I2C LCD display
- Connecting wires

## Libraries Used 📚
- [DFRobot_PAJ7620U2](https://github.com/DFRobot/DFRobot_PAJ7620U2)
- [LiquidCrystal_I2C](https://github.com/johnrickman/LiquidCrystal_I2C)

## Circuit Diagram 🔌

![Circuit Diagram](https://github.com/Circuit-Digest/PAJ7620-Gesture-Recognition-Module-Interfacing-with-Arduino-Uno/blob/main/Circuit%20Diagram.png)

| PAJ7620 | LCD    | Arduino |
|---------|--------|---------|
| VCC     | VCC    | 5V      |
| GND     | GND    | GND     |
| SCL     | SCL    | A5 (SCL)|
| SDA     | SDA    | A4 (SDA)|


## How to Use 🛠️
1. Connect the PAJ7620 Gesture Recognition module and the LCD to the Arduino as per the circuit diagram.
2. Install the required libraries (DFRobot_PAJ7620U2 and LiquidCrystal_I2C) via the Arduino Library Manager.
3. Upload the provided code to your Arduino.
4. Open the Serial Monitor to view the detected gestures and their descriptions.
5. The LCD will display icons and descriptions for the recognized gestures.



## Acknowledgments 🙌
- [DFRobot](https://www.dfrobot.com/) for the PAJ7620 Gesture Recognition module and library.
- [LiquidCrystal_I2C](https://github.com/johnrickman/LiquidCrystal_I2C) for the LCD library.
