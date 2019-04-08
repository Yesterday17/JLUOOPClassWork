//
// Created by Yesterday17 on 4/8.
//

#include "pen.h"

namespace Week6_4 {

Color::Color(uint8_t r, uint8_t g, uint8_t b) {
  this->r = r;
  this->g = g;
  this->b = b;
}

BasePen::BasePen(Color color) {
  this->color = color;
}

Pen::Pen() : BasePen(Color(0x99, 0x99, 0xff)) {

}

Pen::Pen(int64_t nowInk, int64_t totInk, Color color) {
  this->nowInk = nowInk;
  this->totalInk = totInk;
  this->color = color;
}
bool Pen::Write(std::string text) {
  if (this->nowInk - text.length() < 0) {
    return false;
  } else {
    this->nowInk -= text.length();
    return true;
  }
}

int Pen::AddInk(int64_t toAdd) {
  int64_t last = this->totalInk - this->nowInk;
  return (last > toAdd) ? this->nowInk += toAdd, 0 : this->nowInk = this->totalInk, toAdd - last;
}

}