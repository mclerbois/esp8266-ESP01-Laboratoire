/*
  M. Clerbois
  17/10/2015

  Faire clignoter une diode led soit
    une fois toutes les secondes
    ou toutes les 0.2 Secondes.

    La cadence dépend de l'état d'un bouton poussoir.

    On utilise pas la fonction delay
*/

#define USER_BOARD      ESP01   // déclaration de la carte utilisée ESP01 ou ESP201

#include "boards.h"       // déclaration des bornes des cartes

#define LED        GPIO_2      // GPIO_2 connected to LED 
#define PUSHBUTTON GPIO_0      // connected to a push button

long lastTime;
long tempo;
boolean ledState=false;

#define LED_FLASH_SLOW  500
#define LED_FLASH_HIGH  100

void setup() {
  pinMode(LED, OUTPUT);       // Initialize the GPIO_2 pin as an output
  pinMode(PUSHBUTTON,INPUT);  // Initialize the GPIO_0 pin as an input
  lastTime=millis();          // lastime set to actual time
  tempo= digitalRead(PUSHBUTTON) ? LED_FLASH_SLOW : LED_FLASH_HIGH;
  digitalWrite( LED, ledState ? LOW : HIGH); // agir sur la diode led
 }

// the loop function runs over and over again forever
void loop() {
 
  if ( (millis()-lastTime) > tempo) {           //si la temporisation est écoulée
    lastTime=millis();                          // pour la prochaine tempo
    tempo= digitalRead(PUSHBUTTON) ? LED_FLASH_SLOW : LED_FLASH_HIGH; // on relit le bouton poussoir
    ledState=!ledState;                         // ledSate=NOT ledState
    digitalWrite( LED, ledState ? LOW : HIGH);  // agir sur la diode led
    } // fin du if ( (millis()-lastTime) > tempo)       
    
}



