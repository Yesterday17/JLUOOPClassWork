//
// Created by Yesterday17 on 5/13.
//

#ifndef OOPCLASSWORK_WEEK11_2_MONSTER_H
#define OOPCLASSWORK_WEEK11_2_MONSTER_H

#include <cstdint>
#include "../../week6/5/TRandom.h"
namespace WEEK11_2 {
class Monster {
 protected:
  uint64_t hp;
  uint64_t attack;
  uint64_t defense;
  uint64_t attacked(int attack);
  virtual uint64_t attackDamage(Monster &b) {
    return this->attack;
  };
  static Week6_5::TRandom random;
 public:
  Monster();
  Monster(uint64_t hp, uint64_t attack, uint64_t defense);
  void fight(Monster &b);
  void Print();
  uint64_t getDefense() {
    return this->defense;
  };
};
}

#endif //OOPCLASSWORK_WEEK11_2_MONSTER_H
