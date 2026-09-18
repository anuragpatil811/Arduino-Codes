#include <Servo.h>
unsigned int receivedValue = 0;
Servo myservo;  
void setup() {
  myservo.attach(9); 
  Serial.begin(9600);
}

void loop() {

  if (Serial.available()) {
    Serial.println("Data From VC-02");
    byte highByte = Serial.read();
    byte lowByte = Serial.read();
    receivedValue = (highByte << 8) | lowByte;
    Serial.print("Received HEX value: 0x");
    Serial.println(receivedValue, HEX);
  }
  if (receivedValue == 0xA190)  
  {
    myservo.write(90); 
    delay(15);
  } else if (receivedValue == 0xA145) {
    myservo.write(45);  
    delay(15);
  } else {
  }
  delay(10);
  receivedValue = 0;
}
