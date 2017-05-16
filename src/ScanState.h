#ifndef SCANSTATE_H
#define SCANSTATE_H

#include "Arduino.h"

#include "State.h"
// #include "DiscState.h"

class ScanState : public State {
  
  public:
    // ScanState(SoftwareSerial* serial);
    State* onUpdate(SoftwareSerial* serial);
    void onEnter(SoftwareSerial* serial);
    void onExit(SoftwareSerial* serial);  
};

#endif
