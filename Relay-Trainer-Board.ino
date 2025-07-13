const int lm35Pin = A0;      // LM35 output pin
const int relayPin = 7;      // Relay control pin
const float thresholdTemp = 30.0; // Temperature threshold (in Celsius)

void setup() {
  pinMode(relayPin, OUTPUT); // Relay control as output
  digitalWrite(relayPin, LOW); // Initialize relay OFF
  Serial.begin(9600);         // For debugging
}

void loop() {
  // Read temperature from LM35
  int sensorValue = analogRead(lm35Pin);
  float temperature = sensorValue * (5.0 / 1023.0) * 100.0; // Convert to Celsius

  // Print temperature for debugging
  Serial.print("Temperature: ");
  Serial.println(temperature);

  // Control relay based on temperature
  if (temperature > thresholdTemp) {
    digitalWrite(relayPin, HIGH); // Turn relay ON
  } else {
    digitalWrite(relayPin, LOW); // Turn relay OFF
  }

  delay(1000); // Wait 1 second
}
