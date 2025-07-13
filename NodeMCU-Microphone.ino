const int soundSensorPin = D2;  // D0 pin from mic connected to D2 on NodeMCU
const int ledPin = D4;          // Onboard LED on NodeMCU (GPIO2)

void setup() {
  pinMode(soundSensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);    // Make sure LED is OFF initially
  Serial.begin(115200);
}

void loop() {
  int soundDetected = digitalRead(soundSensorPin);

  if (soundDetected == HIGH) {
    digitalWrite(ledPin, LOW);  // LED ON (active LOW)
    Serial.println("🔊 Sound Detected - LED ON");
    delay(1000);                // Keep LED on for 1 second
  } else {
    digitalWrite(ledPin, HIGH); // LED OFF
  }
}
