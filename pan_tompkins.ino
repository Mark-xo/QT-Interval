// Include the libraries
#include <SoftwareSerial.h>
#include <Wire.h>

// Define the pins
#define ECG_PIN A0

// Define the variables
int ecgValue = 0;
int ecgArray[100];
int ecgCounter = 0;

void setup() {
  // Start the serial communication
  Serial.begin(9600);
}

void loop() {
  // Read the ECG value from the sensor
  ecgValue = analogRead(ECG_PIN);

  // Store the ECG value in an array
  ecgArray[ecgCounter] = ecgValue;

  // Increment the counter
  ecgCounter++;

  // If the counter reaches 100, reset it to zero
  if (ecgCounter == 100) {
    ecgCounter = 0;
  }

  // Implement the Pan-Tompkins algorithm to detect QRS complexes
  int qrsStart = -1;
  int qrsEnd = -1;

  for (int i = 0; i < ecgCounter; i++) {
    if (ecgArray[i] > threshold && qrsStart == -1) {
      qrsStart = i;
    }

    if (ecgArray[i] < threshold && qrsStart != -1 && qrsEnd == -1) {
      qrsEnd = i;
    }

    if (qrsStart != -1 && qrsEnd != -1) {
      Serial.print(qrsStart);
      Serial.print(",");
      Serial.print(qrsEnd);
      Serial.println();

      qrsStart = -1;
      qrsEnd = -1;
    }

    delay(10);
  }

  // Print a new line character on the serial monitor
  Serial.println();
}