#ifndef SCAN_STATE_H
#define SCAN_STATE_H

#include "StateInterface.h"

class ScanState : public StateInterface {
  
  public:
    ScanState();
    void onEnter();
    void onUpdate();
    void onExit();
        
};

#endif
