const int micPin = A0;         // Microphone input pin (Analog)
const int buzzerPin = 9;       // Buzzer output pin (Digital)

void setup() {
  pinMode(buzzerPin, OUTPUT);  // Set buzzer pin as output
  Serial.begin(9600);          // Start serial communication for debugging
}

void loop() {
  int micValue = analogRead(micPin);   // Read microphone sensor value
  Serial.println(micValue);             // Print the value to Serial Monitor for debugging

  // If sound detected (threshold value can be adjusted based on testing)
  if (micValue > 500) {       
    tone(buzzerPin, 1000);    // Play sound on the buzzer (1000 Hz tone)
  } else {
    noTone(buzzerPin);        // Stop the buzzer if no sound
  }

  delay(100);  // Small delay for stability
}
