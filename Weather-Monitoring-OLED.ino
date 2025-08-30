#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>
#include <Adafruit_Sensor.h>  // Needed for DHT library

// OLED display size
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// Create display object
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// DHT11 settings
#define DHTPIN 2         // DHT11 data pin connected to Arduino pin 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();

  // Initialize OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // I2C address is usually 0x3C
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }

  display.display();
  delay(2000); // Splash screen delay
  display.clearDisplay();
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature(); // Celsius

  // Check if any read failed
  if (isnan(h) || isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Print to Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" °C  Humidity: ");
  Serial.print(h);
  Serial.println(" %");

  // Display on OLED
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.print("Temp: ");
  display.print(t);
  display.println("C");
  display.print("Hum: ");
  display.print(h);
  display.println("%");
  display.display();

  delay(2000); // Update every 2 seconds
}
