

#include "Arduino.h"
#include "ScanState.h"


ScanState::ScanState() : StateInterface() {
  Serial.write("ScanState constructor");
}

void ScanState::onEnter() {
  Serial.write("ScanState onEnter()");  
}

void ScanState::onUpdate() {
  Serial.write("ScanState onUpdate");  
}

void ScanState::onExit() {
  Serial.write("ScanState onExit");
}
