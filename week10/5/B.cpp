//
// Created by Yesterday17 on 5/6.
//

#include <iostream>
#include "B.h"

WEEK10_5::B::B(int num) {
  this->ptr = new Ptr(num);
}

WEEK10_5::B::~B() {
  this->ptr->count--;
  if (this->ptr->count == 0) {
    delete this->ptr;
    std::cout << u8"内存已释放！" << std::endl;
  } else {
    std::cout << u8"还有" << this->ptr->count << "个引用！" << std::endl;
  }
}

void WEEK10_5::B::detach() {
  // TODO
}
