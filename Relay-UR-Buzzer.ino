// Define pin connections
#define RELAY1 7
#define RELAY2 6
#define BUZZER 4
#define TRIG 3
#define ECHO 5

// Variables for distance calculation
long duration;
int distance;

void setup() {
  // Initialize relay pins as OUTPUT
  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT);

  // Initialize buzzer pin as OUTPUT
  pinMode(BUZZER, OUTPUT);

  // Initialize ultrasonic sensor pins
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  // Start serial communication
  Serial.begin(9600);
}

void loop() {
  // Send a 10-microsecond pulse to trigger pin
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  // Read the echo pin and calculate distance
  duration = pulseIn(ECHO, HIGH);
  distance = duration * 0.034 / 2;

  // Print distance to Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Control relays and buzzer based on distance
  if (distance < 10) {
    digitalWrite(RELAY1, HIGH);  // Turn on relay 1
    digitalWrite(RELAY2, LOW);   // Turn off relay 2
    digitalWrite(BUZZER, HIGH); // Turn on buzzer
  } 
  else if (distance >= 10 && distance <= 20) {
    digitalWrite(RELAY1, LOW);   // Turn off relay 1
    digitalWrite(RELAY2, HIGH);  // Turn on relay 2
    digitalWrite(BUZZER, LOW);  // Turn off buzzer
  } 
  else {
    digitalWrite(RELAY1, LOW);   // Turn off relay 1
    digitalWrite(RELAY2, LOW);   // Turn off relay 2
    digitalWrite(BUZZER, LOW);  // Turn off buzzer
  }

  delay(500); // Delay for stability
}
