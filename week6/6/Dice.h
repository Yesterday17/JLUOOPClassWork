//
// Created by t on 4/8.
//

#ifndef OOPCLASSWORK_Week_6_DICE_H
#define OOPCLASSWORK_Week_6_DICE_H
#include "../5/TRandom.h"

namespace Week6_6 {
class Dice {
 private:
  Week6_5::TRandom random;
  int now;
 public:
  Dice();
  int Roll();
  int Roll(int num);
  int Top();
  int Bottom();
};
}

#endif //OOPCLASSWORK_Week_6_DICE_H
