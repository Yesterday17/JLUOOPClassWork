//
// Created by Yesterday17 on 4/29.
//

#ifndef OOPCLASSWORK_B_H
#define OOPCLASSWORK_B_H

#include "A.h"
namespace WEEK9_1 {
class B : public A {
 public:
  B(int num1, int num2) : A(num1), data2(num2) {}
  B(const B &b) : A(b.data1), data2(b.data2) {} // 拷贝构造函数
  B &operator=(const B &b); // 赋值函数

  ~B() { std::cout << " Destory B" << std::endl; }
  void f() const {
    std::cout << " Excute B::f() ";
    std::cout << " Data1=" << data1;
    std::cout << " Data2=" << data2 << std::endl;
  }
  void f(int n) const {
    std::cout << " Excute B::f(int) ";
    std::cout << " n=" << n;
    std::cout << " Data1=" << data1;
    std::cout << " Data2=" << data2 << std::endl;
  }
  void h() {
    std::cout << " Excute B::h() " << std::endl;
  }
 private:
  int data2;
};
}

#endif //OOPCLASSWORK_B_H
