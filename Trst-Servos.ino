#include <Servo.h>
Servo gripServo;
Servo armServo;

void setup() {
  gripServo.attach(D1);
  armServo.attach(D2);

  gripServo.write(0);   // Release
  delay(2000);
  gripServo.write(45);  // Grip
  delay(2000);
  armServo.write(45);   // Move up
  delay(2000);
  armServo.write(135);  // Move down
}

void loop() {}
