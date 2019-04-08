//
// Created by t on 4/8.
//

#ifndef OOPCLASSWORK_WEEK6_B_H
#define OOPCLASSWORK_WEEK6_B_H

namespace Week6_3 {
#include <iostream>
#include "a.h"

class B {
 public:
  void Func() const {
    std::cout << "This is member function Func()" << std::endl;
  }

 private:
  A aA;
};

class BB {
 public:
  explicit BB(A &aA) {
    pA = &aA;
  }
  void Func() const{
    std::cout << "This is member function Func()" << std::endl;
  }

  void Func2();

  void NewFunc() {
    pA->OtherFunc();
  }

 private:
  A *pA;
};
}

#endif //OOPCLASSWORK_WEEK6_B_H
