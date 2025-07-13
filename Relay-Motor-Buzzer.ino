// Arduino Code for Two-Channel Relay Module, Piezo Buzzer, and DC Motor

// Define pin connections
const int relay1 = 7;       // IN1 connected to pin 7
const int relay2 = 6;       // IN2 connected to pin 6
const int buzzer = 4;       // Piezo buzzer connected to pin 4
const int motor = 5;        // DC motor connected to pin 5

void setup() {
  // Initialize pins as OUTPUT
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(motor, OUTPUT);

  // Turn off all devices initially
  digitalWrite(relay1, LOW);
  digitalWrite(relay2, LOW);
  digitalWrite(buzzer, LOW);
  digitalWrite(motor, LOW);
}

void loop() {
  // Example operation sequence

  // Activate relay 1 and buzzer
  digitalWrite(relay1, HIGH);
  digitalWrite(buzzer, HIGH);
  delay(1000); // Wait 1 second

  // Deactivate buzzer
  digitalWrite(buzzer, LOW);
  delay(500); // Wait 0.5 seconds

  // Activate relay 2 and motor
  digitalWrite(relay2, HIGH);
  digitalWrite(motor, HIGH);
  delay(2000); // Wait 2 seconds

  // Deactivate relay 1, relay 2, and motor
  digitalWrite(relay1, LOW);
  digitalWrite(relay2, LOW);
  digitalWrite(motor, LOW);
  delay(1000); // Wait 1 second before repeating
}
