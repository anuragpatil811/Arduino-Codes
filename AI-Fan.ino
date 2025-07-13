int relayPin = 8;

void setup() {
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW); // Start OFF
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    char command = Serial.read();

    if (command == 'M') {
      digitalWrite(relayPin, HIGH); // Relay ON (Fan ON)
    } 
    else if (command == 'F') {
      digitalWrite(relayPin, LOW);  // Relay OFF (Fan OFF)
    }
  }
}
