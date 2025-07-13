void setup() {
  // Initialize the serial communication at 9600 baud rate
  Serial.begin(9600);
}

void loop() {
  // Check if data is available to read
  if (Serial.available() > 0) {
    // Read the incoming byte
    String received = Serial.readString();
    
    // Print the received message
    Serial.println("Received: " + received);
  }
}
