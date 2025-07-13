
#include <WiFiClient.h>
#include <WiFiServer.h>
#include <WiFiUdp.h>

#include <Wire.h>
#include <MPU6050.h>

MPU6050 gyro;
const int relayPin = 7; // Relay control pin
const float tiltThreshold = 30.0; // Tilt angle threshold in degrees

void setup() {
  Serial.begin(9600);
  Wire.begin();
  gyro.initialize();
  
  pinMode(relayPin, OUTPUT); // Set relay pin as output
  digitalWrite(relayPin, LOW); // Ensure relay is OFF initially

  if (!gyro.testConnection()) {
    Serial.println("MPU6050 connection failed!");
    while (1);
  }
  Serial.println("MPU6050 connected successfully!");
}

void loop() {
  // Read angles from gyro
  float accelX = gyro.getAccelerationX();
  float accelY = gyro.getAccelerationY();
  float accelZ = gyro.getAccelerationZ();
  
  // Calculate tilt angle (basic example using X and Z)
  float angle = atan2(accelX, accelZ) * 180.0 / PI;

  Serial.print("Tilt Angle: ");
  Serial.println(angle);

  // Control relay based on tilt angle
  if (abs(angle) > tiltThreshold) {
    digitalWrite(relayPin, HIGH); // Turn relay ON
  } else {
    digitalWrite(relayPin, LOW); // Turn relay OFF
  }

  delay(100); // Small delay for stability
}
