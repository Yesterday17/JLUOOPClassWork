//
// Created by Yesterday17 on 4/29.
//

#ifndef OOPCLASSWORK_C_H
#define OOPCLASSWORK_C_H

#include <iostream>
#include "A.h"
#include "B.h"
namespace WEEK9_2 {
class C : public A, private B {
 public:
  C(int num1, int num2, int y);
  void MyFuncs() {
    BFuncs();
    std::cout << "This function call B::BFuncs() !" << std::endl;
  }
 private:
  int yyy;
};

class CC : public BB {
 public:
  CC(int num1, int num2, int y);
  CC(const CC &c) : BB(c), yyy(c.yyy) {}
  ~CC();
  CC &operator=(const CC &c) {
    this->yyy = c.yyy;
    this->data = c.data;
    this->value = c.value;
    return *this;
  }
  void MyFuncs() {
    BFuncs();
    std::cout << "This function call B::BFuncs() !" << std::endl;
  }
 private:
  int yyy;
};
}

#endif //OOPCLASSWORK_C_H
