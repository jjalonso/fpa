#ifndef BLUETOOTH_H
#define BLUETOOTH_H

#include "Arduino.h"
#include <SoftwareSerial.h>

#include "Machine.h"

class Bluetooth : public Machine {
  
  public:
    Bluetooth(int rxPin, int txPin);
    void begin();
    void sendAT(char* at);
    void pump();
    

  private:
    int _rxPin;
    int _txPin;
    
};

#endif
