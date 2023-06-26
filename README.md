# QT-Interval
# IoT Project: ECG Sensor Interfacing with Arduino

![ECG Sensor](images/ecg_sensor.jpg)

This is the readme file for an IoT project that involves interfacing the DFRobot ECG Sensor with an Arduino board. The project utilizes algorithms such as Pan-Tompkins and peak detection to analyze ECG signals and determine the QT interval. This readme will guide you through the necessary steps to set up and run the project successfully.

## Table of Contents

- [Introduction](#introduction)
- [Hardware Requirements](#hardware-requirements)
- [Software Requirements](#software-requirements)
- [Circuit Connection](#circuit-connection)
- [Installation](#installation)
- [Usage](#usage)
- [References](#references)

## Introduction

The ECG (Electrocardiography) sensor is used to measure the electrical activity of the heart. This IoT project aims to capture ECG signals using the DFRobot ECG Sensor and process the data to identify the QT interval. The Pan-Tompkins algorithm is employed for QRS complex detection, while peak detection algorithms help identify the P, Q, R, S, and T waves.

## Hardware Requirements

To complete this project, you will need the following hardware components:

- Arduino board (e.g., Arduino Uno)
- DFRobot ECG Sensor
- ECG electrodes
- Jumper wires
- Breadboard (optional)

## Software Requirements

Make sure you have the following software installed:

- Arduino IDE (Integrated Development Environment)
- DFRobot ECG Sensor library for Arduino

## Circuit Connection

Follow these steps to establish the necessary connections between the Arduino board and the ECG sensor:

1. Connect the ECG sensor's VCC pin to the 5V pin on the Arduino.
2. Connect the ECG sensor's GND (ground) pin to the GND pin on the Arduino.
3. Connect the ECG sensor's OUT pin to any of the analog input pins on the Arduino (e.g., A0).
4. Connect the ECG sensor's RA and LA pins to the two ECG electrodes respectively.
5. Connect the ECG sensor's RL pin to the right leg electrode (RL).
6. Optionally, use a breadboard for convenient connections.

![Circuit Connection Diagram](images/circuit_connection_diagram.png)

## Installation

Follow these steps to set up the project:

1. Install the Arduino IDE from the official Arduino website (https://www.arduino.cc/en/software) if you haven't already.
2. Connect the Arduino board to your computer using a USB cable.
3. Open the Arduino IDE.
4. Go to "Sketch" -> "Include Library" -> "Manage Libraries".
5. In the Library Manager, search for "DFRobot ECG Sensor" and click on "Install" to install the library.
6. Wait for the installation to complete.

## Usage (Continued)

9. Implement the Pan-Tompkins algorithm and peak detection algorithms to process the ECG waveform and identify the QT interval. Here are the steps you can follow:

   - Use the ECG sensor readings obtained in the `loop()` function of the Arduino code as input for your algorithm.
   - Apply the Pan-Tompkins algorithm to detect the QRS complex in the ECG waveform. This algorithm aims to identify the Q, R, and S waves, which are crucial for further analysis.
   - Utilize peak detection algorithms to identify the P and T waves. These algorithms help determine the beginning and end of each wave, aiding in the calculation of the QT interval.
   - Once you have identified the relevant waves, calculate the QT interval using appropriate mathematical formulas or algorithms.

10. Modify the code provided in the `loop()` function to incorporate your algorithm for QT interval analysis and waveform processing.

11. Compile and upload the updated code to your Arduino board.

12. Open the Serial Monitor in the Arduino IDE to observe the ECG sensor readings and the calculated QT intervals.

13. Analyze the QT interval data and interpret the results as per your specific requirements or medical guidelines.

14. Make any necessary adjustments to the algorithm and analysis based on the observed results, medical feedback, or research.

15. Iterate and refine your code and analysis methodology as needed until you achieve accurate and reliable QT interval calculations.

## References

- DFRobot ECG Sensor Wiki: [https://wiki.dfrobot.com/EKG_EMG_Sensor_SKU__SEN0213_](https://wiki.dfrobot.com/EKG_EMG_Sensor_SKU__SEN0213_)
- Pan-Tompkins Algorithm: [https://ieeexplore.ieee.org/document/4122029](https://ieeexplore.ieee.org/document/4122029)

Feel free to explore the provided references for more information on the ECG sensor and the Pan-Tompkins algorithm for your project.

**Note:** Make sure to consult medical professionals or experts in the field to ensure accurate analysis and interpretation of ECG signals for any medical applications.
