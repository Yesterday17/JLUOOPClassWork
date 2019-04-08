//
// Created by Yesterday17 on 4/8.
//

#ifndef OOPCLASSWORK_WEEK6_A_H
#define OOPCLASSWORK_WEEK6_A_H

#include <iostream>

namespace Week6_3 {
class A {
 public:
  void Display() const {
    std::cout << "The argment is NULL" << std::endl;
  }

  void Display(const char *str) const {
    std::cout << "The argment is " << str << std::endl;
  }

  void OtherFunc() const {
  }

  // 2.
  inline void Display(const char *str, bool flag) const {
    std::cout << "The argment is " << str << std::endl;
  }
  void Display(const char *str, bool flag1, bool flag2) const;

  // 4.
  int aStaticInt = 114514;
  void getAStaticInt() const {
    std::cout << u8"aStaticInt is: " << aStaticInt << std::endl;
  }
  int aStaticArray[10] = {0};
  void getAStaticArray() const {
    std::cout << u8"sizeof aStaticArray[10] is: " << sizeof(aStaticArray) << std::endl;
  }
};
}

#endif //OOPCLASSWORK_WEEK6_A_H
