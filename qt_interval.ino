const int heartPin = A1;
int ecgSignal[250];  // Array to store ECG signal samples
int length = 250;
// Function declarations
void detectQRS(int* signal, int length, int& qrsOnsetIndex, int& qrsEndIndex, int& tEndIndex);
int detectRPeak(int* signal, int length);
int findQRSOnset(int* signal, int rPeakIndex);
int findQRSEnd(int* signal, int rPeakIndex);
int findTEnd(int* signal, int qrsEndIndex);

float samplingPeriod = 2;

void setup() {
  Serial.begin(115200);
}

void loop() {
  // Read ECG signal from the sensor and store in the array
  for (int i = 0; i < 250; i++) {
    ecgSignal[i] = analogRead(heartPin);
    delay(2);  // Adjust this delay based on your sampling rate
  }

  // Apply Pan-Tompkins algorithm on the stored ECG signal
  int qrsOnsetIndex, qrsEndIndex, tEndIndex;
  detectQRS(ecgSignal, 250, qrsOnsetIndex, qrsEndIndex, tEndIndex);

  // Calculate the QT interval as the time duration between QRS onset and T-end
  float qtInterval = (tEndIndex - qrsOnsetIndex) * samplingPeriod;  // Multiply by sampling period to get the actual time duration

  // Example: Print the QT interval
  Serial.print("QT Interval: ");
  Serial.println(qtInterval);

  delay(1000);  // Delay between iterations
}

void detectQRS(int* signal, int length, int& qrsOnsetIndex, int& qrsEndIndex, int& tEndIndex) {
  // Pan-Tompkins algorithm implementation for QRS complex detection
  // ...

  // Find QRS-onset, QRS-complex, and T-end using detected R-peaks
  // Example: Assuming rPeakIndex is the detected R-peak index
  int rPeakIndex = detectRPeak(signal, length);
  
  // Find QRS-onset as the point where the signal rises above a threshold before the R-peak
  qrsOnsetIndex = findQRSOnset(signal, rPeakIndex);

  // Find QRS-end as the point where the signal falls below a threshold after the R-peak
  qrsEndIndex = findQRSEnd(signal, rPeakIndex);

  // Find T-end as the point where the signal returns to the baseline after the QRS complex
  tEndIndex = findTEnd(signal, qrsEndIndex);
}

int detectRPeak(int* signal, int length) {
  const int windowSize = 20;  // Window size for searching local maxima
  int rPeakIndex = 0;
  int maxPeakValue = signal[0];

  // Iterate through the signal to find the highest peak
  for (int i = 1; i < length; i++) {
    if (signal[i] > maxPeakValue) {
      maxPeakValue = signal[i];
      rPeakIndex = i;
    }
  }

  // Refine the R-peak index by searching for a local maxima within a window
  int start = rPeakIndex - windowSize / 2;
  int end = rPeakIndex + windowSize / 2;

  // Ensure the search window is within the signal boundaries
  if (start < 0)
    start = 0;
  if (end >= length)
    end = length - 1;

  // Find the local maxima within the search window
  for (int i = start; i <= end; i++) {
    if (signal[i] > signal[rPeakIndex]) {
      rPeakIndex = i;
    }
  }

  return rPeakIndex;
}

int findQRSOnset(int* signal, int rPeakIndex) {
  const int searchRange = 30;  // Number of samples to search before the R-peak
  const int threshold = 1000;  // Threshold value for QRS onset detection

  int qrsOnsetIndex = rPeakIndex;

  // Search backward from the R-peak index to find the QRS onset
    for (int i = rPeakIndex - 1; i >= 0 && i >= rPeakIndex - searchRange; i--) {
    if (signal[i] < threshold) {
      qrsOnsetIndex = i;
      break;
    }
  }

  return qrsOnsetIndex;
}

int findQRSEnd(int* signal, int rPeakIndex) {
  const int searchRange = 30;  // Number of samples to search after the R-peak
  const int threshold = 1000;  // Threshold value for QRS end detection

  int qrsEndIndex = rPeakIndex;

  // Search forward from the R-peak index to find the QRS end
  for (int i = rPeakIndex + 1; i < length && i <= rPeakIndex + searchRange; i++) {
    if (signal[i] < threshold) {
      qrsEndIndex = i;
      break;
    }
  }

  return qrsEndIndex;
}


int findTEnd(int* signal, int qrsEndIndex) {
  const int searchRange = 50;  // Number of samples to search after the QRS end
  const int threshold = 500;   // Threshold value for T-end detection

  int tEndIndex = qrsEndIndex;

  // Search forward from the QRS end index to find the T-end
  for (int i = qrsEndIndex + 1; i < length && i <= qrsEndIndex + searchRange; i++) {
    if (signal[i] < threshold) {
      tEndIndex = i;
      break;
    }
  }

  return tEndIndex;
}
