/*
  M. Clerbois
  17/10/2015
  Actions
  
*/

#define USER_BOARD      ESP01   // déclaration de la carte utilisée ESP01 ou ESP201

#include "boards.h"       // déclaration des bornes des cartes

#define LED         GPIO_2
#define PUSH_BUTTON GPIO_0

#define ON          LOW
#define OFF         HIGH


void setup() {
  pinMode(LED,OUTPUT);
  pinMode(PUSH_BUTTON,INPUT);
  digitalWrite(LED,OFF);
  
  Serial.begin(115200); // initialize serial com at 115200 baud
  Serial.println("Waiting messages");
 }

// the loop function runs over and over again forever
void loop() {
 
  if (Serial.available()>0) { // data received
    String message=Serial.readString();
    Serial.print("Message received: ");
    Serial.println(message);
    
    if (message.equals("LEDON")) {
      digitalWrite(LED,ON);
      Serial.println("Has set led ON");
      return;
      }
      
    if (message.equals("LEDOFF")) {
      digitalWrite(LED,OFF);
      Serial.println("Has set led OFF");
      return;
      }

     if (message.equals("BUTTON?")) {
      Serial.println(digitalRead(PUSH_BUTTON) ? "RELEASED" : "PRESSED");
      return;
      }
      
    Serial.print("UNKNOW COMMAND: ");
    Serial.println(message);
    }
    
}
