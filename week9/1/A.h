//
// Created by Yesterday17 on 4/29.
//

#ifndef OOPCLASSWORK_A_H
#define OOPCLASSWORK_A_H

#include <iostream>

namespace WEEK9_1 {
class A {
 public:
  A(int num) : data1(num) {}
  ~A() {
    std::cout << " Destory A" << std::endl;
  }
  void f() const {
    std::cout << " Excute A::f() ";
    std::cout << " Data1=" << data1 << std::endl;
  }
  void g() {
    std::cout << " Excute A::g() " << std::endl;
  }
 protected:
  int data1;
};
}

#endif //OOPCLASSWORK_A_H
