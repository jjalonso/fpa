#ifndef BLUETOOTH_H
#define BLUETOOTH_H

// #include "Arduino.h"
#include <SoftwareSerial.h>

#include "ScanState.h"
#include "Context.h"

class Bluetooth {
  
  public:
    // Bluetooth(int rxPin, int txPin);
    void begin(int rxPin, int txPin);
    // void sendAT(char* at);
    void update();

  private:
    // char* pumpData();
    Context* _context;
    // int _rxPin;
    // int _txPin;
    // int _bufferIndex;
    // char _buffer[78];
    SoftwareSerial* _serial;

};

#endif
