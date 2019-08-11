     
      /*This is working code of APi hitting to get response in JSON format and parsing the JSON data */
      
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
//      const char* ssid = "home";
//      const char* password = "12345678";
      const char* ssid = "Sarver786";
      const char* password = "Devil@007";
      void setup () {
       
      Serial.begin(9600);
      WiFi.begin(ssid, password);
       
      while (WiFi.status() != WL_CONNECTED) {
       
      delay(1000);
      Serial.print("Connecting..");
          
      }
      
      }
       
      void loop() {
       
      if (WiFi.status() == WL_CONNECTED) { //Check WiFi connection status
       
      HTTPClient http;  //Declare an object of class HTTPClient
       StaticJsonDocument<200> doc;
      http.begin("http://localhost:3000/auto");  //Specify request destination
      int httpCode = http.GET();                                                                  //Send the request
      
      if (httpCode > 0) { //Check the returning code
        String payload = http.getString();   //Get the request response payload
       DeserializationError error = deserializeJson(doc, payload);
      
     // Serial.println(payload);                     //Print the response payload
      // Serial.println("\n\n");
        const char* ID = doc["ID"];
            const char* SortAs = doc["SortAs"];
            const char* GlossTerm = doc["GlossTerm"];
            const char* Acronym = doc["Acronym"];
            const char* Abbrev = doc["Abbrev"];
          
         // Print values.
        Serial.println(ID);
        Serial.println(SortAs);
      Serial.println(GlossTerm);
      Serial.println(Acronym);
      Serial.println(Abbrev);
      }
      else{
        Serial.print("ERROR_CODE");
        Serial.println(httpCode);
      }
       
      /*
      {
        "ID": "SGML",
        "SortAs": "SGML",
        "GlossTerm": "Standard Generalized Markup Language",
        "Acronym": "SGML",
        "Abbrev": "ISO 8879:1986"
      }
      */
//        char json[] =
//                    "{\"ID\": \"SGML\",\"SortAs\": \"SGML\",\"Gloss\": \"Standard\",\"Acronym\": \"SGML\",\"Abbrev\": \"ISO\"}";
//       DeserializationError error = deserializeJson(doc, payload);
//      
//      //  // Test if parsing succeeds.
//        if (error) {
//             Serial.print(F("deserializeJson() failed: "));
//          Serial.println(error.c_str());
//          return;
//            }
           
      http.end();   //Close connection
       
      }
       
      delay(3000);    //Send a request every 30 seconds
       
      }
