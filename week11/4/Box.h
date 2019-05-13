//
// Created by Yesterday17 on 5/13.
//

#ifndef OOPCLASSWORK_BOX_H
#define OOPCLASSWORK_BOX_H
#include <vector>
#include "Fruit.h"

namespace WEEK11_4 {
class Box {
 private:
  std::vector<Fruit*> oranges;
  std::vector<Fruit*> apples;
 public:
  int getApples();
  int getOranges();
  void addFruit(bool isApple);
  int newDay();
  int totWeight();
};
}

#endif //OOPCLASSWORK_BOX_H
