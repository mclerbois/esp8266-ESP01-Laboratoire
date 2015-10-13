#include "FS.h"

#pragma GCC diagnostic ignored "-fpermissive"

void setup() {
  Serial.begin(115200);
  Serial.println("");
  delay(1000);
  Serial.println("Mounting FS...");

  if (!SPIFFS.begin()) 
    Serial.println("Failed to mount file system");
  else {
    Serial.println("System File mounted");
    readFile("/lisez-moi.txt");
    readFile("/index.html");
    }
}

  
void loop() {
  // put your main code here, to run repeatedly:

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

