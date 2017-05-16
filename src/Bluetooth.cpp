#include "Bluetooth.h"

// Bluetooth::Bluetooth() {
//   _rxPin = rxPin;
//   _txPin = txPin;
// }

void Bluetooth::begin(int rxPin, int txPin) {
  _serial = new SoftwareSerial(rxPin, txPin);
  _serial->begin(115200);

  ScanState* scanState = new ScanState();
  _context = new Context(scanState, _serial);
}

// void Bluetooth::sendAT(char* at) {
//   _serial->write(at);
//   delay(80);
// }

void Bluetooth::update() {
  _context->update();
}

// char* Bluetooth::pumpData() {
  // while (_serial->available() > 0) {
  //   char c = _serial->read();
  //   if (_bufferIndex < 300 - 1) {
  //     _buffer[_bufferIndex++] = c;
  //     _buffer[_bufferIndex] = 0 ;
  //   }
  // }
  // return _buffer;
// }
