/* --- node.js script ------------
const express = require('express');
const http =require('http');

const app = express();

app.get('/auto',(request,response)=>{
  
  console.log("Api Hitted...");
  response.send("Called");
  
})

app.listen(3000, ()=>{
  console.log("Hello WORLD....");
});

*/

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>
const char* ssid = "Sarver786";
const char* password = "Devil@007";
 
void setup () {
 
Serial.begin(9600);
WiFi.begin(ssid, password);
 
while (WiFi.status() != WL_CONNECTED) {
 
delay(1000);
Serial.print("Connecting..");
//   StaticJsonBuffer<200> jsonBuffer;

  // StaticJsonBuffer allocates memory on the stack, it can be
  // replaced by DynamicJsonBuffer which allocates in the heap.
  //
  // DynamicJsonBuffer  jsonBuffer(200);

  // JSON input string.
  //
  // It's better to use a char[] as shown here.
  // If you use a const char* or a String, ArduinoJson will
  // have to make a copy of the input in the JsonBuffer.
//  char json[] =
//      "{\"sensor\":\"gps\",\"time\":1351824120,\"data\":[48.756080,2.302038]}";

  // Root of the object tree.
  //
  // It's a reference to the JsonObject, the actual bytes are inside the
  // JsonBuffer with all the other nodes of the object tree.
  // Memory is freed when jsonBuffer goes out of scope.
//  JsonObject& root = jsonBuffer.parseObject(json);
//
//  // Test if parsing succeeds.
//  if (!root.success()) {
//    Serial.println("parseObject() failed");
//    return;
    }
 
}
 
void loop() {
 
if (WiFi.status() == WL_CONNECTED) { //Check WiFi connection status
 
HTTPClient http;  //Declare an object of class HTTPClient
 
http.begin("http://192.168.0.102:3000/auto");  //Specify request destination
int httpCode = http.GET();                                                                  //Send the request

if (httpCode > 0) { //Check the returning code

String payload = http.getString();   //Get the request response payload
Serial.println(payload);                     //Print the response payload
 Serial.println("\n\n");
}
 
http.end();   //Close connection
 
}
 
delay(30000);    //Send a request every 30 seconds
 
}
