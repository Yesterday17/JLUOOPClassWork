//
// Created by Yesterday17 on 5/13.
//

#ifndef OOPCLASSWORK_FRUIT_H
#define OOPCLASSWORK_FRUIT_H

namespace WEEK11_4 {
class Fruit {
 private:
  int weight;
  int minWeight;
  int lose;
 public:
  explicit Fruit(int w, int lo) : weight(w), minWeight(w * 3 / 5), lose(lo) {};
  int loseWeight();
  int getWeight();
};
}

#endif //OOPCLASSWORK_FRUIT_H
