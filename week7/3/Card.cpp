//
// Created by Yesterday17 on 4/15.
//

#include "Card.h"
void WEEK7_3::BaseCard::saveBG(uint8_t id) {
  this->bgid = id;
}

void WEEK7_3::BaseCard::setPos(uint8_t x, uint8_t y) {
  this->pos = std::pair(x, y);
}

std::pair<uint8_t, uint8_t> WEEK7_3::BaseCard::getRBPos() {
  return std::pair<uint8_t, uint8_t>(this->pos.first + this->width, this->pos.second - this->height);
}
WEEK7_3::BaseCard::BaseCard(WEEK7_3::BaseCard &c) {
  this->height = c.height;
  this->width = c.width;
  this->bgid = c.bgid;
  this->pos = std::pair(c.pos.first, c.pos.second);
}
bool WEEK7_3::Card::isSameSuit(WEEK7_3::Card d) {
  return this->suit == d.suit;
}
bool WEEK7_3::Card::isSameRank(WEEK7_3::Card d) {
  return this->rank == d.rank;
}
bool WEEK7_3::Card::isSuit(uint8_t suit) {
  return this->suit == suit;
}
bool WEEK7_3::Card::isRank(uint8_t rank) {
  return this->rank == rank;
}

WEEK7_3::Card::Card(WEEK7_3::Card &c) : BaseCard(c) {
  this->ID = c.ID;
  this->rank = c.rank;
  this->suit = c.suit;
}
