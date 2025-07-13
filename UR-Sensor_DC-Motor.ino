// Define pins for L298N Motor Driver
const int motorIN1 = 4; // Motor Driver IN1 connected to Arduino pin 7
const int motorIN2 = 5; // Motor Driver IN2 connected to Arduino pin 8
const int motorENA = 3; // Motor Driver ENA (Enable pin) connected to Arduino pin 9

// Define pins for Ultrasonic Sensor
const int trigPin = 8; // Trig pin of ultrasonic sensor
const int echoPin = 9; // Echo pin of ultrasonic sensor

// Define a variable to store the distance value
long distance;

void setup() {
  // Set Motor Driver pins as output
  pinMode(motorIN1, OUTPUT);
  pinMode(motorIN2, OUTPUT);
  pinMode(motorENA, OUTPUT);

  // Set Ultrasonic Sensor pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Initialize Serial Monitor for debugging
  Serial.begin(9600);
}

void loop() {
  distance = getDistance();

  // Display the distance on Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Control Motor based on distance
  if (distance < 20) { // If object is detected within 20 cm
    stopMotor();
  } else { // If no object is detected
    startMotor();
  }

  delay(200); // Delay between readings
}

// Function to start the motor
void startMotor() {
  digitalWrite(motorIN1, HIGH);
  digitalWrite(motorIN2, LOW);
  analogWrite(motorENA, 200); // Speed control (0 - 255)
  Serial.println("Motor Running");
}

// Function to stop the motor
void stopMotor() {
  digitalWrite(motorIN1, LOW);
  digitalWrite(motorIN2, LOW);
  analogWrite(motorENA, 0);
  Serial.println("Motor Stopped");
}

// Function to calculate distance using Ultrasonic Sensor
long getDistance() {
  // Clear the trigger pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Set the trigger pin high for 10us
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echo pin
  long duration = pulseIn(echoPin, HIGH);

  // Calculate the distance in cm
  long distance = duration * 0.034 / 2;

  return distance;
}
