//
// Created by Yesterday17 on 5/13.
//

#ifndef OOPCLASSWORK_WEEK11_1_B_H
#define OOPCLASSWORK_WEEK11_1_B_H

#include "A.h"
namespace WEEK11_1 {
class B : public A {
 public:
  B() { std::cout << "Lines=" << ++lineno << " Call B::B()" << std::endl; }
  virtual ~B() { std::cout << "Lines=" << ++lineno << " Call B::~B()" << std::endl; }
  //----------------(5)

  virtual int Func1(int n) const { return num + n; }
  virtual int Func1() const
  //--------------------------------------------(6)
  {
    std::cout << "Lines=" << ++lineno << " Call B::Func1() const" << std::endl;
    return num;
  }

  virtual void Func2(int n = 1000)
  //--------------------------------------------(7)
  {
    std::cout << "Lines=" << ++lineno << " Call B::Func2(int) const n=" << n << std::endl;
    num = n;
  }

  void Func3(int n) { num = n; }
  //---------------------------------------------(8)
 protected:
  int num;
};
}

#endif //OOPCLASSWORK_WEEK11_1_B_H
