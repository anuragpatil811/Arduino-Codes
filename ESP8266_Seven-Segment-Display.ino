// Define pins for segments a to g
int segA = D3;
int segB = D8;
int segC= D4;
int segD = D7;
int segE = D2;
int segF = D1;
int segG = D6;

void setup() {
  // Set all segment pins as output
  pinMode(segA, OUTPUT);
  pinMode(segB, OUTPUT);
  pinMode(segC, OUTPUT);
  pinMode(segD, OUTPUT);
  pinMode(segE, OUTPUT);
  pinMode(segF, OUTPUT);
  pinMode(segG, OUTPUT);

  // Display digit 3: a b c d g on, e f off
  digitalWrite(segA, LOW);
  digitalWrite(segB, LOW);
  digitalWrite(segC, LOW);
  digitalWrite(segD, LOW);
  digitalWrite(segE, HIGH);
  digitalWrite(segF, HIGH);
  digitalWrite(segG, LOW);
}

void loop() {
  // Nothing in loop
}
