#ifndef MACHINE_H
#define MACHINE_H

#include "StateInterface.h"

class Machine {
  
  public:
    void update();

  protected:
    void setState(StateInterface* state);

  private:
    StateInterface* _state;
    
};

#endif