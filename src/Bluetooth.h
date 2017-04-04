#ifndef BLUETOOTH_H
#define BLUETOOTH_H

// #include <Arduino.h>
#include <SoftwareSerial.h>

// #include "Beacon.h"
#include "fsm/Machine.h"

class Bluetooth : public Machine {
  
  public:
    Bluetooth(int rxPin, int txPin);

  private:
    SoftwareSerial * _serial;
    // enum BTState { INQ_START, INQ_DEVICE, INQ_END };
    
};

#endif
