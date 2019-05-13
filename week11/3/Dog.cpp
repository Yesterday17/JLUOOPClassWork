//
// Created by Yesterday17 on 5/13.
//

#include "Dog.h"
uint64_t WEEK11_3::Dog::attackDamage(WEEK11_2::Monster &b) {
  if (this->attack + 3 < b.getDefense()) {
    return 2;
  } else {
    return (this->attack - b.getDefense() + 5) * 2;
  }
}
