#include <Arduino.h>
#include <Wire.h>

long poll_interval = 60000; 


void setup() {
  SerialUSB.begin(115200);
  while(!SerialUSB) {}
  SigFox.begin(19200);
  SigFox.print("+++");
  SerialUSB.println("Sigfox ready");
  
  // Wait for everything to setlle
  delay(500);
}

void loop() {
  // Let's run this once only, so we keep it in setup
  ledBlueLight(HIGH);
  SigFox.print("AT$SF=CAFECAFE");
  SigFox.print("\r");
  SerialUSB.println("Message sent");
  ledBlueLight(LOW);
  delay(poll_interval);
}
