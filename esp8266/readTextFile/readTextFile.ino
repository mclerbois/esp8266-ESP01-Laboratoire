#include "FS.h"

#define USER_BOARD  ESP01
#include "boards.h"

#pragma GCC diagnostic ignored "-fpermissive"

#define PUSH_BUTTON GPIO_0

boolean FileSystemMounted=false;

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
    }
}

  
void loop() {
  // put your main code here, to run repeatedly:
  if ( (FileSystemMounted==true) && (digitalRead(PUSH_BUTTON)==0) ){
    readFile("/lisez-moi.txt");
    while((digitalRead(PUSH_BUTTON)==0)); // wait button released
    }
}


void readFile(String filenamte)
{
  File f=SPIFFS.open(filenamte,"r");
    if (f) {
      Serial.println(filenamte+" Open");
      while (f.available()) {
          String line=f.readStringUntil('\n');
          Serial.println(line);
          }
      f.close();
      Serial.println("File Closed");
      }
}

