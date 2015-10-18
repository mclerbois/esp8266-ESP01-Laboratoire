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
#define LED         GPIO_2      // GPIO_2 connected to LED 

#define ON          LOW
#define OFF         HIGH

boolean FileSystemMounted=false;

const char *ssid;
const char *pswd;

StaticJsonBuffer<256> jsonBuffer;

WiFiServer server(10002);
WiFiClient client;
 
String readJsonFile(String filenamte);
void setup() {
  pinMode(PUSH_BUTTON,INPUT);
  pinMode(LED,OUTPUT);
  digitalWrite(LED,OFF);
  
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
      WiFi.begin(ssid, pswd);
      while (WiFi.status() != WL_CONNECTED) {
        delay(2000);
        Serial.println("No wifi found yet   :-( ");
        }
      Serial.println("");
      Serial.println("WiFi connected :-)");  
      Serial.println("IP address: ");
      Serial.println(WiFi.localIP());  
      server.begin();
      }
    else
      Serial.println("Json Parse fail");
    }
}

long actualTime=0L;
void loop() {
  boolean ack=false;
  if ( (FileSystemMounted==true) && (digitalRead(PUSH_BUTTON)==0) ){
    Serial.println("");
    Serial.println("WiFi connected :-)");  
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());  
    while((digitalRead(PUSH_BUTTON)==0));
    }
    
  if (server.hasClient())
    client=server.available();
  
  if (client.connected())
    if (client.available()){
      char buffer[10];
      int n=client.read((uint8_t *) buffer,10);
      buffer[n]='\0'; // end of string
      
      for (int i=0;i<n;i++)
        buffer[i]=toupper(buffer[i]);
        
      if (strcmp(buffer,"LEDON")==0){
        ack=true;
        digitalWrite(LED,ON);
        }
      if (strcmp(buffer,"LEDOFF")==0){
        ack=true;
        digitalWrite(LED,OFF);
         }
        
      Serial.println(buffer);
        client.write(ack ? "ACK" : "NACK");
     
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
  //Serial.println(line);
  return line;
  }
  
