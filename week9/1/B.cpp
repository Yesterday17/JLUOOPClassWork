//
// Created by t on 4/29.
//

#include "B.h"
WEEK9_1::B &WEEK9_1::B::operator=(const WEEK9_1::B &b) {
  this->data1 = b.data1;
  this->data2 = b.data2;
  return *this;
}
