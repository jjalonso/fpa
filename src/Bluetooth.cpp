
#include "Bluetooth.h"

Bluetooth::Bluetooth(int rxPin, int txPin) : Machine() {
  _rxPin = rxPin;
  _txPin = txPin;
}

void Bluetooth::begin() {
  _serial = new SoftwareSerial(_rxPin, _txPin);
  _serial->begin(115200);
}

void Bluetooth::sendAT(char* at) {
  _serial->write(at);
}

void Bluetooth::pump() {
  Serial.write("SerialBuffer pump");
}
