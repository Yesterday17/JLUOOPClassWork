//
// Created by t on 4/8.
//

#include "Dice.h"
namespace Week6_6 {

Dice::Dice() {
  this->now = 1;
}

int Dice::Roll() {
  this->now = this->random.Integer(1, 6);
  return this->now;
}

int Dice::Top() {
  return this->now;
}

int Dice::Bottom() {
  return 7 - this->now;
}
int Dice::Roll(int num) {
  int tot = 0;
  for (int i = 0; i < num; i++)
    tot += this->Roll();
  return tot;
}
}