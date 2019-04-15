//
// Created by Yesterday17 on 4/15.
//

#include "Equipment.h"
WEEK7_4::Equipment *WEEK7_4::Equipment::Equip(uint64_t ch,
                                              uint64_t pr,
                                              uint64_t at,
                                              uint64_t de,
                                              uint64_t ma,
                                              uint64_t all) {
  this->charm = ch;
  this->prestige = pr;
  this->attack = at;
  this->defense = de;
  this->magic = ma;

  this->charm += all;
  this->prestige += all;
  this->attack += all;
  this->defense += all;
  this->magic += all;
  return this;
}

WEEK7_4::Equipment::Equipment() {
  equ[0]->Equip(2, 0, 0, 0, 0, 0);
  equ[1]->Equip(0, 3, 0, 0, 0, 0);
  equ[2]->Equip(0, 0, 1, 0, 0, 0);
  equ[3]->Equip(0, 0, 0, 1, 0, 0);
  equ[4]->Equip(0, 0, 0, 0, 1, 0);
  equ[5]->Equip(0, 0, 0, 0, 0, 1);

  Empty->Equip(0, 0, 0, 0, 0, 0);
}

WEEK7_4::Equipment *WEEK7_4::Equipment::instance() {
  return Empty;
}
WEEK7_4::Equipment *WEEK7_4::Equipment::instance(uint8_t id) {
  if (id <= 5)
    return equ[id - 1];
  else
    return Empty;
}
uint64_t WEEK7_4::Equipment::getCharm() {
  return this->charm;
}
uint64_t WEEK7_4::Equipment::getPrestige() {
  return this->prestige;
}
uint64_t WEEK7_4::Equipment::getAttack() {
  return this->attack;
}
uint64_t WEEK7_4::Equipment::getDefense() {
  return this->defense;
}
uint64_t WEEK7_4::Equipment::getMagic() {
  return this->magic;
}
