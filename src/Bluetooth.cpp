
#include <Arduino.h>

#include "Bluetooth.h"

Bluetooth::Bluetooth(int rxPin, int txPin) : Machine() {
  _serial = new SoftwareSerial(rxPin, txPin); // RX, TX
}

// void Bluetooth::beep() {
  // digitalWrite(_pin, LOW);
  // delay(80);
  // digitalWrite(_pin, HIGH);
  // delay(80);
  // digitalWrite(_pin, LOW);
  // delay(80);
  // digitalWrite(_pin, HIGH);
  // delay(80);
  // digitalWrite(_pin, LOW);
  // delay(200);  
  // digitalWrite(_pin, HIGH);
// }

