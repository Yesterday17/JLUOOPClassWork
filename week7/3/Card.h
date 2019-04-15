//
// Created by Yesterday17 on 4/15.
//

#ifndef OOPCLASSWORK_CARD_H
#define OOPCLASSWORK_CARD_H

#include <cstdint>
#include <map>
#define extends :
namespace WEEK7_3 {
class BaseCard {
 protected:
  uint8_t width;
  uint8_t height;
  uint8_t bgid;
  std::pair<uint8_t, uint8_t> pos;
 public:
  BaseCard(BaseCard &c);
  void saveBG(uint8_t id);
  void setPos(uint8_t x, uint8_t y);
  std::pair<uint8_t, uint8_t> getRBPos();
};

class Card extends BaseCard {
 private:
  uint8_t ID;
  uint8_t rank;
  uint8_t suit;
 public:
  Card(Card &c);
  bool isSameSuit(Card d);
  bool isSameRank(Card d);
  bool isSuit(uint8_t suit);
  bool isRank(uint8_t rank);
};
}
#endif //OOPCLASSWORK_CARD_H
