//
// Created by Yesterday17 on 5/6.
//

#ifndef OOPCLASSWORK_POLICEMAN_H
#define OOPCLASSWORK_POLICEMAN_H
#include "../1/Walker.h"
#include "../1/Thief.h"
#define extends :

namespace WEEK10_2 {
class Policeman extends public WEEK10_1::Walker {
 private:
  int reward = 0;
 public:
  explicit Policeman(int money) : Walker(money) {};
  void catchThief(WEEK10_1::Thief &thief);
  void printReward();
  int getReward();
};
}

#endif //OOPCLASSWORK_POLICEMAN_H
