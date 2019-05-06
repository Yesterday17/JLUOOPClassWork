//
// Created by Yesterday17 on 5/6.
//

#include <iostream>
#include "Woman.h"

void WEEK10_4::Woman::divorce() {
  auto rep = this->man;
  this->man = nullptr;
  std::cout << "Woman " << this->name << " divorced with " << rep->getName() << "." << std::endl;
  if (rep->isMarried()) {
    rep->divorce();
  }
}

bool WEEK10_4::Woman::isMarried() {
  return this->man != nullptr;
}

void WEEK10_4::Woman::marry(WEEK10_4::Man *man) {
  if (this->man != nullptr) {
    std::cout << "Woman " << this->name << " is already married with " << this->getManName() << "!" << std::endl;
    return;
  }
  this->man = man;
  std::cout << "Man " << this->name << " married " << this->getManName() << "!" << std::endl;
  if (!this->man->isMarried())
    this->man->marry(this);
}

WEEK10_4::Man *WEEK10_4::Woman::getMan() {
  return this->man;
}

std::string WEEK10_4::Woman::getName() {
  return this->name;
}

std::string WEEK10_4::Woman::getManName() {
  if (this->man == nullptr) {
    return "NOT_MARRIED";
  } else {
    return this->man->getName();
  }
}
