
/*
  M. Clerbois
  17/10/2015
  echo le message reçu.
  
*/

#define USER_BOARD      ESP01   // déclaration de la carte utilisée ESP01 ou ESP201

#include "boards.h"       // déclaration des bornes des cartes

void setup() {
  Serial.begin(115200); // initialize serial com at 115200 baud
  Serial.println("Waiting messages");
 }

// the loop function runs over and over again forever
void loop() {
 
  if (Serial.available()>0) { // data received
    String message=Serial.readString();
    Serial.print("Message received: ");
    Serial.println(message);
    }
    
}


