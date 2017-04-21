#ifndef STATE_INTERFACE_H
#define STATE_INTERFACE_H

class StateInterface  {

  public:
    virtual ~StateInterface();
    virtual void onEnter() = 0;
    virtual void onUpdate() = 0;
    virtual void onExit() = 0;
  
};

#endif