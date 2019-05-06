//
// Created by Yesterday17 on 5/6.
//

#include <iostream>
#include "Paginate.h"
WEEK10_8::Paginate WEEK10_8::Paginate::setPage(int n, int tot) {
  this->now = n;
  this->total = tot;
  return *this;
}
WEEK10_8::Paginate WEEK10_8::Paginate::next() {
  if (this->now < this->total)this->now++;
  return *this;
}
WEEK10_8::Paginate WEEK10_8::Paginate::prev() {
  if (this->now > 0)this->now--;
  return *this;
}
WEEK10_8::Paginate WEEK10_8::Paginate::nextN() {
  for (int i = 0; i < 5; i++)next();
  return *this;
}
WEEK10_8::Paginate WEEK10_8::Paginate::prevN() {
  for (int i = 0; i < 5; i++)prev();
  return *this;
}
void WEEK10_8::Paginate::show() {
  std::cout << "上页 ";
  for (int i = 0; i < this->total; i++) {
    std::cout << i + 1;
    if (i + 1 == this->now) {
      std::cout << "+";
    }
    std::cout << " ";
  }
  std::cout << " 下页" << std::endl;
}
