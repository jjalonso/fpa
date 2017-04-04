
#include "Machine.h"

void Machine::setState(State * state) {
  if () _state.onExit();
  _state = state;
  _state.onEnter();
}

void Machine::update(void) {
  _state.onUpdate();
}

