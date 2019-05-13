//
// Created by Yesterday17 on 5/13.
//

#include "Cat.h"

uint64_t WEEK11_3::Cat::attackDamage(Monster &b) {
  if (this->attack * 2 < b.getDefense() + 1) {
    return 1;
  } else {
    return this->attack * 2 - b.getDefense();
  }
}
