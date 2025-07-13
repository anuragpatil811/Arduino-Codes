int relayPin = 7;

void setup() {
  Serial.begin(9600);
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW); // Relay OFF initially
}

void loop() {
  if (Serial.available()) {
    char command = Serial.read();

    if (command == 'L') {          // Light ON
      digitalWrite(relayPin, HIGH);
    } else if (command == 'O') {   // Light OFF
      digitalWrite(relayPin, LOW);
    }

    // You can include other controls like:
    // 'H' -> Hold, 'R' -> Release, etc.
  }
}
