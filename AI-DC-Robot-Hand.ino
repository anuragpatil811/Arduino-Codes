#define IN1 D1  // Motor A - Hold/Release
#define IN2 D2
#define IN3 D5  // Motor B - Arm Up/Down
#define IN4 D6

void setup() {
  Serial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {
  if (Serial.available()) {
    char command = Serial.read();

    switch (command) {
      case 'H':  // Hold
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        break;
      case 'R':  // Release
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        break;
      case 'U':  // Move Up
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
        break;
      case 'D':  // Move Down
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
        break;
      case 'S':  // Stop
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, LOW);
        break;
    }
  }
}
