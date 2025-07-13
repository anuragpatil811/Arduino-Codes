#include <ESP8266WiFi.h>
#include <Servo.h>

Servo myservo;

const int servoPin = D1;         // Servo motor connected to D2 (GPIO4)
const int irSensorPin = D2;      // IR sensor connected to D1 (GPIO5)
int lastIR = -1;

void setup() {
  Serial.begin(9600);
  myservo.attach(servoPin);
  pinMode(irSensorPin, INPUT);
}

void loop() {
  int irValue = digitalRead(irSensorPin);

  // Only act if state changes to avoid repeated servo movement
  if (irValue != lastIR) {
    lastIR = irValue;

    if (irValue == 0) { // Obstacle detected
      myservo.write(0);  // Forward
      Serial.println("IR:0");
    } else {
      myservo.write(180); // Backward
      Serial.println("IR:1");
    }

    delay(500); // Debounce delay
  }
}
