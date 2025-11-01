#include <Wire.h>
#include <MPU6050.h>
MPU6050 mpu;

// Using Motor B side
#define ENB 25   // GPIO25
#define B1  26   // GPIO26
#define B2  27   // GPIO27

void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22);  // SDA = GPIO21, SCL = GPIO22
  mpu.initialize();

  pinMode(ENB, OUTPUT);
  pinMode(B1, OUTPUT);
  pinMode(B2, OUTPUT);

  Serial.println("MPU6050 Gyro-Motor (Motor B side) Test Started");
}

void loop() {
  int16_t ax, ay, az;
  mpu.getAcceleration(&ax, &ay, &az);

  // Calculate tilt on X-axis
  float tilt = atan2(ay, az) * 180 / PI;
  Serial.print("Tilt Angle: ");
  Serial.println(tilt);

  // Map tilt to motor speed (0–255)
  int speed = map(abs(tilt), 0, 90, 0, 255);
  analogWrite(ENB, speed);

  if (tilt > 5) {
    // Tilted right → rotate forward
    digitalWrite(B1, HIGH);
    digitalWrite(B2, LOW);
  } else if (tilt < -5) {
    // Tilted left → rotate reverse
    digitalWrite(B1, LOW);
    digitalWrite(B2, HIGH);
  } else {
    // Balanced → stop motor
    digitalWrite(B1, LOW);
    digitalWrite(B2, LOW);
  }

  delay(100);
}
