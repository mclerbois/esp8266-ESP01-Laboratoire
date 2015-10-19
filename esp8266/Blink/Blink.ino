/*
  M. Clerbois
  17/10/2015

  Faire clignoter une diode led soit
    une fois toutes les deux secondes
    ou toutes les 0.4 Secondes.

    La cadence dépend de l'état d'un bouton poussoir.
*/

#define USER_BOARD      ESP01   // déclaration de la carte utilisée ESP01 ou ESP201

#include "boards.h"             // déclaration des bornes des cartes

#define LED        GPIO_2       // GPIO_2 connected to LED 
#define PUSHBUTTON GPIO_0       // connected to a push button


void setup() {
  pinMode(LED, OUTPUT);       // Initialize the GPIO_2 pin as an output
  pinMode(PUSHBUTTON,INPUT);  // Initialize the GPIO_0 pin as an input
  }

// the loop function runs over and over again forever
void loop() {
  /*
   * long tempo -> on déclare une variable nommée tempo dont le type est entier long 32 bits.
   * long tempo = --> on déclare est donne une valeur à cette variable
   * long tempo = test si différent de 0 ? valeur si vrai : valeur si faux
   *              test si different de 0, on lit l'entrée GPIO_0 le résultat vaut: 
   *                0 si le bouton poussoir est activé
   *                1 si le bouton poussoir est relaché
   *                
   * Si le bouton poussoir est relaché, la temporisation vaudra 1000 mSec.               
   * Si le bouton poussoir est activé, la temporisation vaudra 200 mSec.
   * 
   */
  long tempo= digitalRead(PUSHBUTTON) ? 1000 : 200;  // set tempo for 1000 ou 200 milliSecondes
  digitalWrite( LED, LOW);           // Turn the LED on                                
  delay(tempo);                      // Wait for a 1000 or 200 mSec
  digitalWrite( LED, HIGH);          // Turn the LED off 
  delay(tempo);                      // Wait for a 1000 or 200 mSec
}



