//
// Created by Yesterday17 on 4/15.
//

#include "Hero.h"
WEEK7_4::Hero *WEEK7_4::Hero::Equip(uint8_t slot, uint8_t equipment) {
  if (slot >= 0 && slot <= 5)
    this->equipments[slot - 1] = Equipment::instance(equipment);
  return this;
}
WEEK7_4::Hero *WEEK7_4::Hero::Remove(uint8_t slot) {
  if (slot >= 0 && slot <= 5)
    this->equipments[slot - 1] = Equipment::instance();
  return this;
}
uint64_t WEEK7_4::Hero::getCharm() {
  uint64_t ch = this->charm;
  for (auto i : equipments)
    ch += i->getCharm();
  return ch;
}
uint64_t WEEK7_4::Hero::getPrestige() {
  uint64_t pr = this->prestige;
  for (auto i : equipments)
    pr += i->getPrestige();
  return pr;
}
uint64_t WEEK7_4::Hero::getAttack() {
  uint64_t at = this->attack;
  for (auto i : equipments)
    at += i->getAttack();
  return at;
}
uint64_t WEEK7_4::Hero::getDefense() {
  uint64_t de = this->defense;
  for (auto i : equipments)
    de += i->getDefense();
  return de;
}
uint64_t WEEK7_4::Hero::getMagic() {
  uint64_t ma = this->magic;
  for (auto i : equipments)
    ma += i->getMagic();
  return ma;
}
