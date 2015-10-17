/*
  M. Clerbois
  17/10/2015

  
*/

#define USER_BOARD      ESP01   // déclaration de la carte utilisée ESP01 ou ESP201

#include "boards.h"       // déclaration des bornes des cartes

void setup() {
  Serial.begin(115200); // initialize serial com at 115200 baud
 }

// the loop function runs over and over again forever
void loop() {
 
  Serial.println("Hello");
  delay(1000);
    
}



