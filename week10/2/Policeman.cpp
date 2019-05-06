//
// Created by t on 5/6.
//

#include <iostream>
#include "Policeman.h"
void WEEK10_2::Policeman::catchThief(WEEK10_1::Thief &thief) {
  this->money += thief.thieved();
  this->reward++;
}

void WEEK10_2::Policeman::printReward() {
  std::cout << this->reward * 100;
}
int WEEK10_2::Policeman::getReward() {
  return this->reward;
}
