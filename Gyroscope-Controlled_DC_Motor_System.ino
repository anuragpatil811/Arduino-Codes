#include <Wire.h>

const int motorA1 = 9;   // Motor A control pin 1
const int motorA2 = 10;  // Motor A control pin 2
const int motorENA = 3;  // Motor A enable pin (PWM)

void setup() {
  // Motor setup
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorENA, OUTPUT);

  // Gyro setup
  Wire.begin();
  Serial.begin(9600);
  
  // Initialize MPU-6050 gyro (I2C address: 0x68)
  Wire.beginTransmission(0x68);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission();
}

void loop() {
  // Gyroscope data
  Wire.beginTransmission(0x68);
  Wire.write(0x3B); // Start reading from register 0x3B
  Wire.endTransmission(false);
  Wire.requestFrom(0x68, 6, true);

  int16_t gyroX = Wire.read() << 8 | Wire.read();
  int16_t gyroY = Wire.read() << 8 | Wire.read();
  int16_t gyroZ = Wire.read() << 8 | Wire.read();

  Serial.print("Gyro X: "); 
  Serial.println(gyroX);
 Serial.print("Gyro Y: "); 
  Serial.println(gyroY);
  // Motor control based on gyroX
  if (gyroX > 1000) {
    digitalWrite(motorA1, HIGH);
    digitalWrite(motorA2, LOW);
    analogWrite(motorENA, 150); // Moderate speed
  } else if (gyroX < -1000) {
    digitalWrite(motorA1, LOW);
    digitalWrite(motorA2, HIGH);
    analogWrite(motorENA, 150); // Moderate speed
  } else {
    digitalWrite(motorA1, LOW);
    digitalWrite(motorA2, LOW); // Stop motor
  }

  delay(2000);
}
