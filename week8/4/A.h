//
// Created by Yesterday17 on 4/22.
//

#ifndef OOPCLASSWORK_A_H
#define OOPCLASSWORK_A_H

namespace WEEK8_4 {

class A {
 public:
  explicit A(int n) : data(n) {}
  int Data() const { return data; }
 private:
  int data;
};

void g(int n);

}

#endif //OOPCLASSWORK_A_H
