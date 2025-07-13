/*#include <ArduinoJson.h>
#include <ESP8266HTTPClient.h>
#include<Arduino.h>
#include<WiFi.h>

const char* ssid = "Room009";
const char* password = "Sadguru009";
const char* Gemini_Token = "AIzaSyAJquOUd-jvNhxoJIIRW6XIaj9pzgvQYfI";*/
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClientSecure.h>  // Required for HTTPS connections
#include <ArduinoJson.h>

const char* ssid = "Galaxy A22 5G 4862";
const char* password = "lezc4808";
const char* Gemini_Token = "AIzaSyAJquOUd-jvNhxoJIIRW6XIaj9pzgvQYfI";
const char* Gemini_Max_Tokens = "100";

String res = "";

void setup() {
  Serial.begin(115200);

  WiFi.disconnect();  

  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  
  Serial.println("\nConnected to WiFi");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  Serial.println("\nAsk your Question: ");
  while (!Serial.available());

  while (Serial.available()) {
    char add = Serial.read();
    res = res + add;
    delay(1);
  }

  int len = res.length();
  res = res.substring(0, (len - 1));
  res = "\"" + res + "\"";

  Serial.print("Asking Your Question: ");
  Serial.println(res);

  WiFiClientSecure client;  // Create secure client for HTTPS
  client.setInsecure();     // Disable SSL certificate verification (required if using an insecure connection)

  HTTPClient https;
  if (https.begin(client, "https://generativelanguage.googleapis.com/v1beta/models/gemini-1.5-flash:generateContent?key=" + (String)Gemini_Token)) {
    https.addHeader("Content-Type", "application/json");

    String payload = "{\"contents\": [{\"parts\":[{\"text\":" + res + "}]}],\"generationConfig\": {\"maxOutputTokens\": " + (String)Gemini_Max_Tokens + "}}";

    int httpCode = https.POST(payload);

    if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
      String response = https.getString();
      
      DynamicJsonDocument doc(1024);
      deserializeJson(doc, response);
      String Answer = doc["candidates"][0]["content"]["parts"][0]["text"];

      Answer.trim();
      String filteredAnswer = "";
      for (size_t i = 0; i < Answer.length(); i++) {
        char c = Answer[i];
        if (isalnum(c) || isspace(c)) {
          filteredAnswer += c;
        } else {
          filteredAnswer += ' ';
        }
      }
      Answer = filteredAnswer;

      Serial.println("\nHere is your Answer: ");
      Serial.println(Answer);
    } else {
      Serial.printf("[HTTPS] Request failed, error: %s\n", https.errorToString(httpCode).c_str());
    }
    https.end();
  } else {
    Serial.println("[HTTPS] Unable to connect");
  }
  res = "";
}
