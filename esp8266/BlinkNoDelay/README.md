BLINK
=========================================

Faire clignoter une diode led soit
   
-  une fois toutes les  secondes
   
-  ou toutes les 0.2 Secondes.

    La cadence dépend de l'état d'un bouton poussoir.

##  board.h

Le fichier "boards.h" contient les déclarations des bornes des cartes

Il faut déclarer USER_BOARD avec soit ESP01 ou ESP201

 #define USER_BOARD      ESP01   // déclaration de la carte utilisée ESP01 ou ESP201

 #include "boards.h"             // déclaration des bornes des cartes

## blink.ino

Le fichier "blink.ino" contient le code du programme.

Cette version n'utilise pas la fonction delay(...)

## Led et bouton poussoir

- La diode led est connectée à GPIO_2.
- Le bouton poussoir est connecté à GPIO_0.

