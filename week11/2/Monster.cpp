//
// Created by Yesterday17 on 5/13.
//

#include "Monster.h"
#include <string>
#include <iostream>

Week6_5::TRandom WEEK11_2::Monster::random;

WEEK11_2::Monster::Monster() {
  this->hp = random.Integer(100, 500);
  this->attack = random.Integer(10, 50);
  this->defense = random.Integer(10, 50);
}
WEEK11_2::Monster::Monster(uint64_t hp, uint64_t attack, uint64_t defense) {
  this->hp = hp;
  this->attack = attack;
  this->defense = defense;
}
void WEEK11_2::Monster::fight(WEEK11_2::Monster &b) {
  WEEK11_2::Monster *sequence[2];
  std::string names[2];

  std::cout << "A";
  this->Print();

  std::cout << "B";
  b.Print();

  while (this->hp != 0 && b.hp != 0) {
    sequence[0] = this;
    sequence[1] = &b;
    names[0] = "A";
    names[1] = "B";

    // Attack
    std::cout << names[0] << u8"先攻击，造成" << sequence[1]->attacked(sequence[0]->attackDamage(*sequence[1])) << u8"点伤害。" << std::endl;
    std::cout << names[1];
    sequence[1]->Print();

    if (sequence[1]->hp == 0) break;

    std::cout << names[1] << u8"后攻击，造成" << sequence[0]->attacked(sequence[1]->attackDamage(*sequence[0])) << u8"点伤害。" << std::endl;
    std::cout << names[0];
    sequence[0]->Print();

    std::cout << std::endl;
  }
  std::cout << (sequence[0]->hp == 0 ? names[1] : names[0]) << u8"死亡，" << (sequence[0]->hp != 0 ? names[1] : names[0])
            << u8"获胜！" << std::endl;
}
uint64_t WEEK11_2::Monster::attacked(int att) {
  uint64_t damage = 1;
  if (2 * att > this->defense)
    damage = 2 * att - this->defense;

  if (damage <= this->hp)
    this->hp -= damage;
  else
    this->hp = 0;
  return damage;
}

void WEEK11_2::Monster::Print() {
  std::cout << u8"目前状态：" << std::endl;
  std::cout << u8"HP: " << this->hp << std::endl;
  std::cout << u8"攻击: " << this->attack << std::endl;
  std::cout << u8"防御: " << this->defense << std::endl;
  std::cout << std::endl;
}
