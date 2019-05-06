//
// Created by Yesterday17 on 5/6.
//

#include <iostream>
#include "Walker.h"

int WEEK10_1::Walker::thieved() {
  int stolen = this->money;
  this->money = 0;
  return stolen;
}
void WEEK10_1::Walker::printMoney() {
  std::cout << this->money;
}
