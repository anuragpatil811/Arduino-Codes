// Pin configuration
const int controlPin = 7; // Shared pin for relay and buzzer

void setup() {
  pinMode(controlPin, OUTPUT); // Set the pin as output
}

void loop() {
  digitalWrite(controlPin, HIGH); // Turn relay and buzzer ON
  delay(1000); // Wait 1 second

  digitalWrite(controlPin, LOW); // Turn relay and buzzer OFF
  delay(1000); // Wait 1 second
}
