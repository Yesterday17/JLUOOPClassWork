//
// Created by Yesterday17 on 4/15.
//

#ifndef OOPCLASSWORK_EQUIPMENT_H
#define OOPCLASSWORK_EQUIPMENT_H

#include <cstdint>
namespace WEEK7_4 {
class Equipment {
 private:
  uint64_t charm = 0;
  uint64_t prestige = 0;
  uint64_t attack = 0;
  uint64_t defense = 0;
  uint64_t magic = 0;

  Equipment();
  Equipment *Equip(uint64_t ch, uint64_t pr, uint64_t at, uint64_t de, uint64_t ma, uint64_t all);
  static Equipment *equ[6];
  static Equipment *Empty;

 public:
  static Equipment *instance();
  static Equipment *instance(uint8_t id);
  uint64_t getCharm();
  uint64_t getPrestige();
  uint64_t getAttack();
  uint64_t getDefense();
  uint64_t getMagic();
};
}

#endif //OOPCLASSWORK_EQUIPMENT_H
