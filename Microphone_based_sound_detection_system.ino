// Pin configuration
const int analogPin = A0;  // A0 connected to analog output of KY-038
const int digitalPin = 2;  // D2 connected to digital output of KY-038
const int ledPin = 13;     // Built-in LED to indicate sound detection (optional)

// Variables
int analogValue = 0;       // To store analog readings
int digitalValue = 0;      // To store digital readings

void setup() {
  pinMode(digitalPin, INPUT);  // Set digital pin as input
  pinMode(ledPin, OUTPUT);     // Set LED pin as output (optional)
  Serial.begin(9600);          // Start serial communication
}

void loop() {
  // Read analog value from the microphone
  analogValue = analogRead(analogPin);
  
  // Read digital value from the microphone
  digitalValue = digitalRead(digitalPin);

  // Print analog and digital values to the Serial Monitor
  Serial.print("Analog Value: ");
  Serial.print(analogValue);
  Serial.print(" | Digital Value: ");
  Serial.println(digitalValue);

  // If digital output is HIGH (sound detected), turn on the LED
  if (digitalValue == HIGH) {
    digitalWrite(ledPin, HIGH);  // Turn LED on
    Serial.println("Sound detected!");
  } else {
    digitalWrite(ledPin, LOW);   // Turn LED off
  }

  delay(100);  // Small delay for stability
}
