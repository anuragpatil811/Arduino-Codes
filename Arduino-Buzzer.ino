#define BUZZER_PIN 8  // Connect buzzer + to pin 8, - to GND

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  // First beep
  digitalWrite(BUZZER_PIN, HIGH);  // Beep ON
  delay(200);
  digitalWrite(BUZZER_PIN, LOW);   // Beep OFF
  delay(200);

  // Second beep
  digitalWrite(BUZZER_PIN, HIGH);
  delay(200);
  digitalWrite(BUZZER_PIN, LOW);

  // Wait before next "beep beep"
  delay(1000);
}
