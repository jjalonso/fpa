
#include "Context.h"

Context::Context(State* firstState, SoftwareSerial* serial) {
  _serial = serial;
  _setState(firstState);
}

void Context::_setState(State* state) {
  // if (_state != 0) {
  //   _state->onExit(_serial);
  // }
  _state = state;
  _state->onEnter(_serial);
}

void Context::update() {
  State* updatedState = _state->onUpdate(_serial);
  if (updatedState != _state) {
    _setState(updatedState);
  }
}

