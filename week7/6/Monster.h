//
// Created by Yesterday17 on 4/15.
//

#ifndef OOPCLASSWORK_MONSTER_H
#define OOPCLASSWORK_MONSTER_H

#include <cstdint>
#include "../../week6/5/TRandom.h"
namespace WEEK7_6 {
class Monster {
 private:
  uint64_t hp;
  uint64_t attack;
  uint64_t defense;
  uint64_t speed;
  uint64_t attacked(int attack);
  static Week6_5::TRandom random;
 public:
  Monster();
  Monster(uint64_t hp, uint64_t attack, uint64_t defense, uint64_t speed);
  void fight(Monster &b);
  void Print();
};
}

#endif //OOPCLASSWORK_MONSTER_H
