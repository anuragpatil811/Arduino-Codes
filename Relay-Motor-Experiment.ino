int relayPin = 7;

void setup() {
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW); // Keep motor OFF initially
}

void loop() {
  digitalWrite(relayPin, HIGH);  // Turn motor ON
  delay(500);                   // Keep ON for 3 seconds
  digitalWrite(relayPin, LOW);   // Turn motor OFF
  delay(500);                  // Keep OFF for 2 seconds
}
