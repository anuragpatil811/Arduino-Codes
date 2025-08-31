void setup() 
{
 pinMode(12, INPUT_PULLUP);
 pinMode(13, OUTPUT);
}

void loop() 
{
  int val = digitalRead(12);
  //Serial.print(val);
  Serial.println(val);
  digitalWrite(13, val);
}
