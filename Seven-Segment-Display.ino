int segmentA = 2;
int segmentB = 3;
int segmentC = 4;
int segmentD = 5;
int segmentE = 6;
int segmentF = 7;
int segmentG = 8;

// Create a 2D array to represent the segments for digits 0-9
int digits[10][7] = {
  {1, 1, 1, 1, 1, 1, 0},  // 0
  {0, 1, 1, 0, 0, 0, 0},  // 1
  {1, 1, 0, 1, 1, 0, 1},  // 2
  {1, 1, 1, 1, 0, 0, 1},  // 3
  {0, 1, 1, 0, 0, 1, 1},  // 4
  {1, 0, 1, 1, 0, 1, 1},  // 5
  {1, 0, 1, 1, 1, 1, 1},  // 6
  {1, 1, 1, 0, 0, 0, 0},  // 7
  {1, 1, 1, 1, 1, 1, 1},  // 8
  {1, 1, 1, 0, 0, 1, 1}   // 9
};

void setup() {
  // Set segment pins as output
  pinMode(segmentA, OUTPUT);
  pinMode(segmentB, OUTPUT);
  pinMode(segmentC, OUTPUT);
  pinMode(segmentD, OUTPUT);
  pinMode(segmentE, OUTPUT);
  pinMode(segmentF, OUTPUT);
  pinMode(segmentG, OUTPUT);
}

void loop() {
  // Loop through the digits 0-9
  for (int i = 0; i <= 9; i++) {
    displayDigit(i);  // Display the current digit
    delay(5000);      // Wait for 1 second before displaying the next digit
  }
}

// Function to display a digit on the seven-segment display
void displayDigit(int num) {
  digitalWrite(segmentA, digits[num][0]);
  digitalWrite(segmentB, digits[num][1]);
  digitalWrite(segmentC, digits[num][2]);
  digitalWrite(segmentD, digits[num][3]);
  digitalWrite(segmentE, digits[num][4]);
  digitalWrite(segmentF, digits[num][5]);
  digitalWrite(segmentG, digits[num][6]);
}
