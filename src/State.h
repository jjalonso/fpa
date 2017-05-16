#ifndef STATE_H
#define STATE_H

#include <SoftwareSerial.h>

class State  {

  public:
    virtual State* onUpdate(SoftwareSerial* serial) = 0;
    virtual void onEnter(SoftwareSerial* serial) = 0;
    virtual void onExit(SoftwareSerial* serial) = 0;

  protected:
    SoftwareSerial* _serial;

};

#endif