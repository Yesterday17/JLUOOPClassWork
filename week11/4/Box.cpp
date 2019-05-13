//
// Created by Yesterday17 on 5/13.
//

#include <iostream>
#include "Box.h"
int WEEK11_4::Box::getApples() {
  return this->apples.size();
}
int WEEK11_4::Box::getOranges() {
  return this->oranges.size();
}
void WEEK11_4::Box::addFruit(bool isApple) {
  if (isApple) {
    this->apples.push_back(new Fruit(50, 4));
    std::cout << "放入一个苹果" << std::endl;
  } else {
    this->oranges.push_back(new Fruit(30, 3));
    std::cout << "放入一个橘子" << std::endl;
  }

}
int WEEK11_4::Box::newDay() {
  int lose = 0;
  for (auto a : this->apples) {
    lose += a->loseWeight();
  }
  for (auto o : this->oranges) {
    lose += o->loseWeight();
  }
  std::cout << "新的一天，减少重量为： " << lose << std::endl;
  return lose;
}
int WEEK11_4::Box::totWeight() {
  int weight = 0;
  for (auto a : this->apples) {
    weight += a->getWeight();
  }
  for (auto o : this->oranges) {
    weight += o->getWeight();
  }
  return weight;
}
