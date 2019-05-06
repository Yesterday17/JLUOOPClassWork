//
// Created by Yesterday17 on 5/6.
//

#include <iostream>
#include "Man.h"

bool WEEK10_4::Man::isMarried() {
  return this->woman != nullptr;
}
void WEEK10_4::Man::marry(WEEK10_4::Woman *woman) {
  if (this->woman != nullptr) {
    std::cout << "Man " << this->name << " is already married with " << this->getWomanName() << "!" << std::endl;
    return;
  }
  this->woman = woman;
  std::cout << "Man " << this->name << " married " << this->getWomanName() << "!" << std::endl;
  if (!this->woman->isMarried())
    this->woman->marry(this);
}

void WEEK10_4::Man::divorce() {
  auto rep = this->woman;
  this->woman = nullptr;
  std::cout << "Man " << this->name << " divorced with " << rep->getName() << "." << std::endl;
  if (rep->isMarried()) {
    rep->divorce();
  }
}
WEEK10_4::Woman *WEEK10_4::Man::getWoman() {
  return this->woman;
}
std::string WEEK10_4::Man::getName() {
  return this->name;
}
std::string WEEK10_4::Man::getWomanName() {
  if (this->woman == nullptr) {
    return "NOT_MARRIED";
  } else {
    return this->woman->getName();
  }
}
