//
// Created by Yesterday17 on 5/6.
//

#ifndef OOPCLASSWORK_WOMAN_H
#define OOPCLASSWORK_WOMAN_H

#include "Man.h"
namespace WEEK10_4 {
class Man;
class Woman {
 private:
  std::string name;
  Man *man = nullptr;
 public:
  explicit Woman(std::string n) : name(n) {};
  bool isMarried();
  void marry(Man *man);
  void divorce();
  Man *getMan();
  std::string getManName();
  std::string getName();
};
}

#endif //OOPCLASSWORK_WOMAN_H
