
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

// Replace with your network credentials
const char* ssid = "Gearbox Members";
const char* password = "Members@Gearbox";

String serverName = "http://192.168.0.176:8000/";
WiFiClient client;
HTTPClient http;

unsigned long previousMillis = 0;
unsigned long interval = 30000;



void initWiFi() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi ..");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    delay(1000);
  }
  Serial.println(WiFi.localIP());
}

void setup() {
  Serial.begin(9600);
  initWiFi();
  Serial.print("RRSI: ");
  Serial.println(WiFi.RSSI());
}

void loop() {
  unsigned long currentMillis = millis();
  // if WiFi is down, try reconnecting every CHECK_WIFI_TIME seconds
  if ((WiFi.status() != WL_CONNECTED) && (currentMillis - previousMillis >=interval)) {
    Serial.print(millis());
    Serial.println("Reconnecting to WiFi...");
    WiFi.disconnect();
    WiFi.begin(ssid, password);
    Serial.println(WiFi.localIP());
    //Alternatively, you can restart your board
    //ESP.restart();
    Serial.println(WiFi.RSSI());
    previousMillis = currentMillis;
  }


      // Free resources
      http.end();

      char c;
      while (Serial.available()) {
         c = Serial.read(); //gets one byte from serial buffer
//        Serial.println(c);
      String serverPath = serverName + "?data=" + c;

      http.begin(client, serverPath.c_str());
     // Send HTTP GET request
     int httpResponseCode = http.GET();

      }
        delay(100);



}