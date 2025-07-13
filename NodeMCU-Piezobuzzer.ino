#define BUZZER_PIN D1  // GPIO5

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  // First beep
  digitalWrite(BUZZER_PIN, HIGH);  // Beep ON
  delay(200);                      // Duration of beep
  digitalWrite(BUZZER_PIN, LOW);   // Beep OFF
  delay(200);                      // Pause between beeps

  // Second beep
  digitalWrite(BUZZER_PIN, HIGH);
  delay(200);
  digitalWrite(BUZZER_PIN, LOW);

  // Wait before next "beep-beep" cycle
  delay(1000);  // Delay between "beep beep" groups
}
