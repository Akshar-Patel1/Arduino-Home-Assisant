#include <SPI.h>
#include <WiFiNINA.h>
#include <ArduinoJson.h>

const char* ssid = "YOUR_SSID";
const char* password = "YOUR_PASSWORD";
void setup() {
 Serial.begin(115200);
 WiFi.begin(ssid, password);
 while (WiFi.status() != WL_CONNECTED) {
   delay(1000);
   Serial.println("Connecting...");
 }
}
void loop() {
 // Check WiFi Status
 if (WiFi.status() == WL_CONNECTED) {
   HTTPClient http;  //Object of class HTTPClient
   http.begin("http://yourip/api/Home/GetAllApp");
   int httpCode = http.GET();
   //Check the returning code                                                                  
   if (httpCode > 0) {
     // Get the request response payload
     String payload = http.getString();
     // TODO: Parsing
     Serial.println(payload);
   }
   http.end();   //Close connection
 }
 // Delay
 delay(3000);
}