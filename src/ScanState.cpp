
#include "ScanState.h"

// ScanState::ScanState(SoftwareSerial* serial) : State(SoftwareSerial* serial) {

// } 

void ScanState::onEnter(SoftwareSerial* serial) {
  Serial.println("ScanOnEnter ");
  serial->write("AT+LESCAN\r\n");
  // serial->write("AT+LESCAN\r\n");
}

 State* ScanState::onUpdate(SoftwareSerial* serial) {
  Serial.println("ScanOnUpdate ");
  Serial.println(serial->readString());
  return this;
  // DiscState* discState = new DiscState();
  // return discState;
}

void ScanState::onExit(SoftwareSerial* serial) {
  Serial.println("ScanOnExit ");
}
