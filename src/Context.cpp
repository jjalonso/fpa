
#include "Machine.h"

void Machine::setState(StateInterface* state) {
  if (state != 0) {
    _state->onExit();
    delete _state;
  }
  _state = state;
  _state->onEnter();
}

void Machine::update() {
  _state->onUpdate();
}

