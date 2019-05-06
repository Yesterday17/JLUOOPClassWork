//
// Created by Yesterday17 on 5/6.
//

#ifndef OOPCLASSWORK_THIEF_H
#define OOPCLASSWORK_THIEF_H
#include "Walker.h"
#define extends :

namespace WEEK10_1 {
class Thief extends public Walker {
 public:
  Thief() : Walker() {};
  explicit Thief(int money) : Walker(money) {};
  void steal(Walker &walker);
};
}

#endif //OOPCLASSWORK_THIEF_H
