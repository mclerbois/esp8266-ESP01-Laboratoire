/*
 ESP8266 Blink by Simon Peter
 Blink the blue LED on the ESP-01 module
 This example code is in the public domain
 
 The blue LED on the ESP-01 module is connected to GPIO1 
 (which is also the TXD pin; so we cannot use Serial.print() at the same time)
 
 Note that this sketch uses BUILTIN_LED to find the pin with the internal LED
*/

#define GPIO_0     0 // INPUT !!! Flash button 
#define GPIO_2     2
#define GPIO_4     4
#define GPIO_5     5
#define GPIO_12    12
#define GPIO_13    13
#define GPIO_14    14
#define GPIO_15    15 // 10K pull down for startupt

#define LED        13
#define PUSHBUTTON GPIO_0 


void setup() {
  pinMode( LED, OUTPUT);     // Initialize the BUILTIN_LED pin as an output
  pinMode(PUSHBUTTON,INPUT);
 }

// the loop function runs over and over again forever
void loop() {
  long tempo= digitalRead(PUSHBUTTON) ? 1000 : 200;
  digitalWrite( LED, LOW);   // Turn the LED on (Note that LOW is the voltage level
                                    // but actually the LED is on; this is because 
                                    // it is acive low on the ESP-01)
  delay(tempo);                      // Wait for a second
  digitalWrite( LED, HIGH);  // Turn the LED off by making the voltage HIGH
  delay(tempo);                      // Wait for two seconds (to demonstrate the active low LED)
}
