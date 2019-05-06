//
// Created by Yesterday17 on 5/6.
//

#ifndef OOPCLASSWORK_MAN_H
#define OOPCLASSWORK_MAN_H

#include "Woman.h"

namespace WEEK10_4 {
class Woman;
class Man {
 private:
  std::string name;
  Woman *woman = nullptr;
 public:
  explicit Man(std::string n) : name(n) {};
  bool isMarried();
  void marry(Woman *woman);
  void divorce();
  Woman *getWoman();
  std::string getWomanName();
  std::string getName();
};
}

#endif //OOPCLASSWORK_MAN_H
