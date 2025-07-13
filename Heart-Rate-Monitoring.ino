#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_RESET -1
Adafruit_SSD1306 display(OLED_RESET);
const int pulsePin = A0;
int BPM;
int Signal;
int Threshold = 550; 
void setup() 
{
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.print("Heart Rate");
  display.display();
  delay(2000);
}
void loop() 
{
  Signal = analogRead(pulsePin);
  BPM = map(Signal, Threshold, 1023, 60, 120); 
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(0,0);
  display.print("BPM: ");
  display.print(BPM);
  display.display();
  delay(1000);
}
