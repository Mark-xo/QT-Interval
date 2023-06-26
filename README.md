# QT-Interval
IoT Project: ECG Sensor Interfacing with Arduino
ECG Sensor

This is the readme file for an IoT project that involves interfacing the DFRobot ECG Sensor with an Arduino board. The project utilizes algorithms such as Pan-Tompkins and peak detection to analyze ECG signals and determine the QT interval. This readme will guide you through the necessary steps to set up and run the project successfully.

Table of Contents
Introduction
Hardware Requirements
Software Requirements
Circuit Connection
Installation
Usage
References
Introduction
The ECG (Electrocardiography) sensor is used to measure the electrical activity of the heart. This IoT project aims to capture ECG signals using the DFRobot ECG Sensor and process the data to identify the QT interval. The Pan-Tompkins algorithm is employed for QRS complex detection, while peak detection algorithms help identify the P, Q, R, S, and T waves.

Hardware Requirements
To complete this project, you will need the following hardware components:

Arduino board (e.g., Arduino Uno)
DFRobot ECG Sensor
ECG electrodes
Jumper wires
Breadboard (optional)
Software Requirements
Make sure you have the following software installed:

Arduino IDE (Integrated Development Environment)
DFRobot ECG Sensor library for Arduino
Circuit Connection
Follow these steps to establish the necessary connections between the Arduino board and the ECG sensor:

Connect the ECG sensor's VCC pin to the 5V pin on the Arduino.
Connect the ECG sensor's GND (ground) pin to the GND pin on the Arduino.
Connect the ECG sensor's OUT pin to any of the analog input pins on the Arduino (e.g., A0).
Connect the ECG sensor's RA and LA pins to the two ECG electrodes respectively.
Connect the ECG sensor's RL pin to the right leg electrode (RL).
Optionally, use a breadboard for convenient connections.
Circuit Connection Diagram

Installation
Follow these steps to set up the project:

Install the Arduino IDE from the official Arduino website (https://www.arduino.cc/en/software) if you haven't already.
Connect the Arduino board to your computer using a USB cable.
Open the Arduino IDE.
Go to "Sketch" -> "Include Library" -> "Manage Libraries".
In the Library Manager, search for "DFRobot ECG Sensor" and click on "Install" to install the library.
Wait for the installation to complete.
Usage
Now that everything is set up, you can start using the project:

Open the Arduino IDE.
Connect the Arduino board to your computer.
Copy and paste the sample code provided below into the Arduino IDE.
arduino

Compile and upload the code to your Arduino board.
Open the Serial Monitor in the Arduino IDE (you can use the shortcut: Ctrl + Shift + M).
You should start seeing ECG sensor readings printed in the Serial Monitor.
Implement the Pan-Tompkins algorithm and peak detection algorithms to process the ECG waveform and identify the QT interval.
Modify the code as necessary to suit your specific analysis requirements.
Note: The provided code is a basic starting point to read ECG values. You need to extend it by adding your own implementation of the Pan-Tompkins algorithm and peak detection algorithms to calculate the QT interval and analyze the ECG waveform further.

References
DFRobot ECG Sensor Wiki: https://wiki.dfrobot.com/EKG_EMG_Sensor_SKU__SEN0213_
Pan-Tompkins Algorithm: https://ieeexplore.ieee.org/document/4122029
Feel free to explore the provided references for more information on the ECG sensor and the Pan-Tompkins algorithm for your project.

Note: Make sure to consult medical professionals or experts in the field to ensure accurate analysis and interpretation of ECG signals for any medical applications.
