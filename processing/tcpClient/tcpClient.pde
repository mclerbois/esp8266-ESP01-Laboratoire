/**
 * Doit être utilisé avec WifiTcpServer (esp8266)
 */


import processing.net.*;

Client c;
String input;

void setup() 
{
  size(450, 255);
  background(204);
  stroke(0);
  frameRate(5); // Slow it down a little
  // Connect to the server's IP address and port
  c = new Client(this, "192.168.0.8", 10002); // Replace with your server's IP and port
}
boolean ledState=false;
boolean ack=true;

void draw() 
{
  if ((mousePressed == true) && ack) {
    ack=false;
    ledState=!ledState;
    if (ledState)
      c.write("LEDON");
    else
      c.write("LEDOFF");
    }
  // Receive data from server
  if (c.available() > 0) {
    input = c.readString();
    println(input);
    if (input.equals("ACK"))
      ack=true;
  }
}
