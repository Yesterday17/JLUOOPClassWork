//
// Created by Yesterday17 on 4/15.
//

#ifndef OOPCLASSWORK_HERO_H
#define OOPCLASSWORK_HERO_H

#include <cstdint>
#include <vector>
#include "Equipment.h"
namespace WEEK7_4 {
class Hero {
 private:
  uint64_t charm;
  uint64_t prestige;
  uint64_t attack;
  uint64_t defense;
  uint64_t magic;

  Equipment *equipments[5] = {Equipment::instance()};
 public:
  Hero *Equip(uint8_t slot, uint8_t equipment);
  Hero *Remove(uint8_t slot);
  uint64_t getCharm();
  uint64_t getPrestige();
  uint64_t getAttack();
  uint64_t getDefense();
  uint64_t getMagic();
};
}

#endif //OOPCLASSWORK_HERO_H
