int a=8;

void setup() {
pinMode(a,OUTPUT);

}

void loop() {
digitalWrite(a,1);
delay(2000);

digitalWrite(a,0);
delay(2000);
}
