//
// Created by Yesterday17 on 4/29.
//

#ifndef OOPCLASSWORK_92_B_H
#define OOPCLASSWORK_92_B_H

#include <iostream>
#include "A.h"

namespace WEEK9_2 {
class B {
 public:
  explicit B(int num) : value(num) {}
  void BFuncs() { std::cout << "This is B \'s public function!" << std::endl; }
 protected:
  int value;
};

class BB : public AA {
 public:
  BB(int anum, int num) : AA(anum), value(num) {}
  BB(const BB &b) : AA(b), value(b.value) {}
  ~BB();
  void BFuncs() { std::cout << "This is B \'s public function!" << std::endl; }
 protected:
  int value;
};
}

#endif //OOPCLASSWORK_B_H
