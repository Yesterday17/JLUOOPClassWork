//
// Created by Yesterday17 on 4/15.
//

#ifndef OOPCLASSWORK_DEMO_H
#define OOPCLASSWORK_DEMO_H

#include <iostream>
namespace WEEK7_5 {
class Demo {
 private:
  int mNum;
  Demo() { mNum = 0; }
 public:
  void AddValue(int value) { mNum += value; }
  void ShowValue() const { std::cout << "Value=" << mNum << std::endl; }
  static Demo *getInstance() {
    static Demo instance;
    return &instance;
  }
};
}

#endif //OOPCLASSWORK_DEMO_H
