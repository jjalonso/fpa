#ifndef CONTEXT_H
#define CONTEXT_H

#include <Arduino.h>
#include <SoftwareSerial.h>

#include "State.h"

class Context {
  
  public:
    Context(State* firstState, SoftwareSerial* serial);
    void update();

  private:
    void _setState(State* state);
    State* _state;
    SoftwareSerial* _serial;
};

#endif