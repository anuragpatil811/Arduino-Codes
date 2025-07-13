// Define pin numbers
const int trigPin = 9;    // Pin for the Ultrasonic sensor's Trig
const int echoPin = 10;   // Pin for the Ultrasonic sensor's Echo
const int buzzerPin = 8;  // Pin for the Piezo Buzzer

// Variables for duration and distance
long duration;
int distance;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  
  // Set pin modes
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Clear the trigPin by setting it LOW
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Set the trigPin HIGH for 10 microseconds to send the pulse
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echoPin, and calculate the duration of the pulse
  duration = pulseIn(echoPin, HIGH);

  // Calculate the distance in cm (Sound speed = 34300 cm/s)
  distance = duration * 0.034 / 2;

  // Print the distance to the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // If the object is closer than 10 cm, trigger the buzzer
  if (distance < 10) {
    tone(buzzerPin, 1000);  // Sound the buzzer at 1000 Hz
  } else {
    noTone(buzzerPin);  // Turn off the buzzer
  }

  // Small delay before next loop
  delay(100);
}
