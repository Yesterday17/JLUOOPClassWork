//
// Created by Yesterdat17 on 5/13.
//

#ifndef OOPCLASSWORK_WEEK11_1_A_H
#define OOPCLASSWORK_WEEK11_1_A_H

#include <iostream>
namespace WEEK11_1 {
class A {
 public:
  A() { std::cout << "Lines=" << ++lineno << " Call A::A()" << std::endl; }
  virtual ~A() { std::cout << "Lines=" << ++lineno << " Call A::~A()" << std::endl; }
  //----------------(1)

  virtual int Func1() const = 0;
  //-----------------------------------------------(2)

  virtual void Func2(int= 500) = 0;
  //-----------------------------------------------(3)
 protected:
  //-------------------------------------------------------------(4)
  static int lineno;
};
}

#endif //OOPCLASSWORK_WEEK11_1_A_H
