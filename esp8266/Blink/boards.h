/*
  Déclaration des bornes utilisables pour deux types de carte ESP8266
*/

#if !defined(__BOARDS_H_)
#define     __BOARDS_H_

#if !defined(USER_BOARD)
#error No Board defined!
#endif

#if USER_BOARD == ESP01   // Pour une carte ESP01
#define GPIO_0     0 // INPUT PULLUP 10K !!! Flash button or switch
#define GPIO_2     2 // connected to a PULLUP 10K
#define GPIO_1     1 // OUTPUT connected to RXD of programming device
#define TX         1 // OUTPUT connected to RXD of communicating device
#define GPIO_3     3 // INPUT  connected to TXD of programming device
#define RX         3 // INPUT  connected to TXD of communicating device
#endif

#if USER_BOARD == ESP201  // Pour une carte ESP201
#define GPIO_0     0 // INPUT PULLUP 10K !!! Flash button or switch
#define GPIO_2     2 // connected to a PULLUP 10K
#define GPIO_1     1 // OUTPUT connected to RXD of programming device
#define TX         1 // OUTPUT connected to RXD of communicating device
#define GPIO_3     3 // INPUT  connected to TXD of programming device
#define RX         3 // INPUT  connected to TXD of communicating device
#define GPIO_4     4
#define GPIO_5     5
#define GPIO_12    12
#define GPIO_13    13
#define GPIO_14    14
#define GPIO_15    15 // 10K pull down for startupt
#endif

#endif

