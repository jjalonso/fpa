#ifndef STATE_H
#define STATE_H

class State  {

  public:
    virtual ~State();
    virtual void onEnter() = 0;
    virtual void onUpdate() = 0;
    virtual void onExit() = 0;
  
};

#endif