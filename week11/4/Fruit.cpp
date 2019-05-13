//
// Created by Yesterday17 on 5/13.
//

#include "Fruit.h"
int WEEK11_4::Fruit::loseWeight() {
  if (this->weight > this->minWeight) {
    this->weight -= this->lose;
    return this->lose;
  } else {
    return 0;
  }
}
int WEEK11_4::Fruit::getWeight() {
  return this->weight;
}
