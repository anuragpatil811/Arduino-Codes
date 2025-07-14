void setup() {
  pinMode(7, OUTPUT);
   pinMode(8,OUTPUT);
}

void loop() {
  digitalWrite(8, HIGH);
  digitalWrite(7,LOW);
  delay(2000);
   digitalWrite(8, LOW);
  digitalWrite(7,HIGH);
  delay(2000);
   digitalWrite(8, LOW);
  digitalWrite(7,LOW);
  delay(1000);
}
