#ifndef MACHINE_H
#define MACHINE_H

#include "State.h"

class Machine {
  
  public:
    void update();
    void setState(State * state);

  protected:
    State * _state;
};

#endif