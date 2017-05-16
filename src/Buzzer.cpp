
#include "Buzzer.h"

Buzzer::Buzzer(int pin) {
  _pin = pin;
}

void Buzzer::begin() {
  pinMode (_pin, OUTPUT) ;
  digitalWrite(_pin, HIGH);
}

void Buzzer::beep() {
  digitalWrite(_pin, LOW);
  delay(80);
  digitalWrite(_pin, HIGH);
  delay(80);
  digitalWrite(_pin, LOW);
  delay(80);
  digitalWrite(_pin, HIGH);
  delay(80);
  digitalWrite(_pin, LOW);
  delay(200);  
  digitalWrite(_pin, HIGH);
}