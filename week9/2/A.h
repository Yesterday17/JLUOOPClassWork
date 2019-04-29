//
// Created by Yesterday17 on 4/29.
//

#ifndef OOPCLASSWORK_92_A_H
#define OOPCLASSWORK_92_A_H
#include <iostream>

namespace WEEK9_2 {
class A {
 public:
  explicit A(int num) : data(num) {}
  void AFuncs() { std::cout << "This is A \'s public function!" << std::endl; }
 protected:
  int data;
};

class AA {
 public:
  explicit AA(int num) : data(num) {}
  AA(const AA &a) : data(a.data) {}
  ~AA();
  void AFuncs() { std::cout << "This is AA \'s public function!" << std::endl; }
 protected:
  int data;
};
}

#endif //OOPCLASSWORK_A_H
