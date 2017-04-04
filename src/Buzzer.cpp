/*
  Buzzer.cpp - Library for active buzzer.
*/

#include <Arduino.h>

#include "Buzzer.h"

Buzzer::Buzzer(int pin) {
  pinMode(pin, OUTPUT);
  _pin = pin;
  pinMode (_pin, OUTPUT) ;
  digitalWrite(_pin, HIGH);  
}

/*
  Beep the buzzer
*/
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