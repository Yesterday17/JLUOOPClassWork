//
// Created by Yesterday17 on 4/29.
//

#include "C.h"
WEEK9_2::CC::CC(int num1, int num2, int y) : BB(num1, num2), yyy(y) {
}

WEEK9_2::CC::~CC() {
  std::cout << "Destruct CC" << std::endl;
}
