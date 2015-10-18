/*
 *
 */

#include <ESP8266WiFi.h>

#include "FS.h"
#include <ArduinoJson.h>

#define USER_BOARD  ESP01
#include "boards.h"

#pragma GCC diagnostic ignored "-fpermissive"

#define PUSH_BUTTON GPIO_0

boolean FileSystemMounted=false;

const char *ssid;
const char *pswd;
const char *ipServer;
int portServer;

StaticJsonBuffer<256> jsonBuffer;

WiFiClient client;

String readJsonFile(String filenamte);
void setup() {
   pinMode(PUSH_BUTTON,INPUT);
  
  Serial.begin(115200);
  Serial.println("");
  delay(1000);
  Serial.println("Mounting FS...");

  if (!SPIFFS.begin()) 
    Serial.println("Failed to mount file system");
  else {
    Serial.println("System File mounted");
    FileSystemMounted=true;
    JsonObject& root = jsonBuffer.parseObject(readJsonFile("/data.json"));
    if (root.success()) {
      //Serial.println("Json Parse success");
      ssid= root["ssid"];
      pswd= root["pswd"];
      ipServer= root["ip"];
      portServer=root["port"];
      WiFi.begin(ssid, pswd);
      while (WiFi.status() != WL_CONNECTED) {
        delay(2000);
        Serial.println("No wifi found yet   :-( ");
        }
      Serial.println("");
      Serial.println("WiFi connected :-)");  
      Serial.println("IP address: ");
      Serial.println(WiFi.localIP());  
      for(;;) {
        Serial.println("Try to connect to Server :-(");
        Serial.println(ipServer);
        if (client.connect(ipServer, portServer))
          break;    
        delay(1000);
        }
      client.write("hello",5);
      }
    else
      Serial.println("Json Parse fail");
    }
}

void loop() {
  if ( (FileSystemMounted==true) && (digitalRead(PUSH_BUTTON)==0) ){
    Serial.println("");
    Serial.println("WiFi connected :-)");  
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());

    if (client.connected())
      client.write("hello",5);
    else{
      Serial.println("Please restart server");
      Serial.println("Try to reconnect");
      client.connect(ipServer, portServer);
      }
      
    while((digitalRead(PUSH_BUTTON)==0));
    }
  if (client.connected())
    if (client.available()){
      char buffer[40];
      int n=client.read((uint8_t *) buffer,40);
      buffer[n]='\0'; // end of string
      Serial.println(buffer);
    }
    
}

String readJsonFile(String filenamte)
{
  String line="";
  File f=SPIFFS.open(filenamte,"r");
    if (f) {
      //Serial.println(filenamte+" Open");
      while (f.available()) {
          line+=f.readStringUntil('\n');
          }
      f.close();
      //Serial.println("File Closed");
      }
  Serial.println(line);
  return line;
  }
  
