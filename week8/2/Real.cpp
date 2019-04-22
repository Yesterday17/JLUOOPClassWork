//
// Created by Yesterday17 on 4/22.
//

#include <iostream>
#include "Real.h"

namespace WEEK8_2 {

Real::Real(double number, int stage) {
  this->stage = stage;
  this->number = number;
  this->part = int(number);

  if (stage < Real::MAXLEN)
    this->next = new Real(1 / (number - double(this->part)), stage + 1);
  else
    this->next = nullptr;
}

RealResult &Real::operator[](const unsigned int &r) {
  auto now = this;
  auto ans = new RealResult();
  std::vector<int> c;

  // string
  for (int i = 0; i <= r && now != nullptr; i++, now = now->next) {
    if (now->stage != 0)
      ans->str += "+";
    ans->str += std::to_string(now->part);
    c.push_back(now->part);
  }

  ans->index = r + 1;
  ans->denominator = 1;
  ans->part = ans->numerator = c[c.size() - 1];

  for (auto i = c.size() - 1; i != 0; i--) {
    ans->denominator += c[i - 1] * ans->numerator;
    std::swap(ans->denominator, ans->numerator);
  }
  std::swap(ans->denominator, ans->numerator);

  ans->value = double(ans->denominator) / double(ans->numerator);
  ans->offset = this->number - ans->value;
  return *ans;
}

}
