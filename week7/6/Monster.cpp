//
// Created by Yesterday17 on 4/15.
//

#include "Monster.h"
#include <string>
#include <iostream>

Week6_5::TRandom WEEK7_6::Monster::random;

WEEK7_6::Monster::Monster() {
  this->hp = random.Integer(100, 500);
  this->attack = random.Integer(10, 50);
  this->defense = random.Integer(10, 50);
  this->speed = random.Integer(10, 50);
}
WEEK7_6::Monster::Monster(uint64_t hp, uint64_t attack, uint64_t defense, uint64_t speed) {
  this->hp = hp;
  this->attack = attack;
  this->defense = defense;
  this->speed = speed;
}
void WEEK7_6::Monster::fight(WEEK7_6::Monster &b) {
  Week6_5::TRandom random;
  WEEK7_6::Monster *sequence[2];
  std::string names[2];

  std::cout << "A";
  this->Print();

  std::cout << "B";
  b.Print();

  while (this->hp != 0 && b.hp != 0) {
    if (this->speed != b.speed) {
      sequence[0] = this->speed > b.speed ? this : &b;
      sequence[1] = this->speed > b.speed ? &b : this;
      names[0] = this->speed > b.speed ? "A" : "B";
      names[1] = this->speed > b.speed ? "B" : "A";
    } else if (this->hp != b.hp) {
      sequence[0] = this->hp > b.hp ? this : &b;
      sequence[1] = this->hp > b.hp ? &b : this;
      names[0] = this->hp > b.hp ? "A" : "B";
      names[1] = this->hp > b.hp ? "B" : "A";
    } else if (this->attack != b.attack) {
      sequence[0] = this->attack > b.attack ? this : &b;
      sequence[1] = this->attack > b.attack ? &b : this;
      names[0] = this->attack > b.attack ? "A" : "B";
      names[1] = this->attack > b.attack ? "B" : "A";
    } else if (this->defense != b.defense) {
      sequence[0] = this->defense > b.defense ? this : &b;
      sequence[1] = this->defense > b.defense ? &b : this;
      names[0] = this->defense > b.defense ? "A" : "B";
      names[1] = this->defense > b.defense ? "B" : "A";
    } else {
      auto rnd = random.Integer(0, 1);
      sequence[0] = rnd ? this : &b;
      sequence[1] = rnd ? &b : this;
      names[0] = rnd ? "A" : "B";
      names[1] = rnd ? "B" : "A";
    }

    // Attack
    std::cout << names[0] << "先攻击，造成" << sequence[1]->attacked(sequence[0]->attack) << "点伤害。" << std::endl;
    std::cout << names[1];
    sequence[1]->Print();

    if (sequence[1]->hp == 0) break;

    std::cout << names[1] << "后攻击，造成" << sequence[0]->attacked(sequence[1]->attack) << "点伤害。" << std::endl;
    std::cout << names[0];
    sequence[0]->Print();

    std::cout << std::endl;
  }
  std::cout << (sequence[0]->hp == 0 ? names[1] : names[0]) << "死亡，" << (sequence[0]->hp != 0 ? names[1] : names[0])
            << "获胜！" << std::endl;
}
uint64_t WEEK7_6::Monster::attacked(int att) {
  uint64_t damage = 1;
  if (2 * att > this->defense)
    damage = 2 * att - this->defense;

  if (damage <= this->hp)
    this->hp -= damage;
  else
    this->hp = 0;
  return damage;
}
void WEEK7_6::Monster::Print() {
  std::cout << "目前状态：" << std::endl;
  std::cout << "HP: " << this->hp << std::endl;
  std::cout << "攻击: " << this->attack << std::endl;
  std::cout << "防御: " << this->defense << std::endl;
  std::cout << "速度: " << this->speed << std::endl;
  std::cout << std::endl;
}
