#include "FS.h"
#include <ArduinoJson.h>

#define USER_BOARD  ESP01
#include "boards.h"

#pragma GCC diagnostic ignored "-fpermissive"

#define PUSH_BUTTON GPIO_0

boolean FileSystemMounted=false;

const char *ssid;
const char *pswd;

StaticJsonBuffer<200> jsonBuffer;

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
      Serial.println("Json Parse success");
      ssid= root["ssid"];
      pswd= root["pswd"];
      }
    else
      Serial.println("Json Parse fail");
    }
}

  
void loop() {
  // put your main code here, to run repeatedly:
  if ( (FileSystemMounted==true) && (digitalRead(PUSH_BUTTON)==0) ){
    Serial.print("SSID = ");
    Serial.println(ssid);
    Serial.print("PASSWORD = ");
    Serial.println(pswd);
    while((digitalRead(PUSH_BUTTON)==0));
    }
}



String readJsonFile(String filenamte)
{
  String line="";
  File f=SPIFFS.open(filenamte,"r");
    if (f) {
      Serial.println(filenamte+" Open");
      while (f.available()) {
          line+=f.readStringUntil('\n');
          }
      f.close();
      Serial.println("File Closed");
      }
  Serial.println(line);
  return line;
  }

