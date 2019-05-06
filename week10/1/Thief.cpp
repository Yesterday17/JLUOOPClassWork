//
// Created by Yesterday17 on 5/6.
//

#include "Thief.h"
void WEEK10_1::Thief::steal(WEEK10_1::Walker &walker) {
  this->money += walker.thieved();
}
