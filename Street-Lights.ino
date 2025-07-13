// Define pins
const int trigPin = 9;
const int echoPin = 10;
const int ledPin1 = 11;
const int ledPin2 = 12;
const int ledPin3 = 13;

// Define a threshold distance (e.g., 100 cm)
const int thresholdDistance = 100;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  
  // Initialize pin modes
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
}

void loop() {
  // Clear the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Set the trigPin HIGH for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echoPin
  long duration = pulseIn(echoPin, HIGH);

  // Calculate the distance
  int distance = duration * 0.034 / 2;

  // Print the distance to the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);

  // Turn all LEDs on if an object is within the threshold distance
  if (distance < thresholdDistance) {
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, HIGH);
  } else {
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
  }

  // Short delay before the next loop
  delay(100);
}
