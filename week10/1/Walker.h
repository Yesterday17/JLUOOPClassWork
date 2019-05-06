//
// Created by Yesterday17 on 5/6.
//

#ifndef OOPCLASSWORK_WALKER_H
#define OOPCLASSWORK_WALKER_H

namespace WEEK10_1 {
class Walker {
 protected:
  int money;
 public:
  Walker() {
    this->money = 0;
  }

  explicit Walker(int money) {
    this->money = money;
  }

  int thieved();
  void printMoney();
};
}

#endif //OOPCLASSWORK_WALKER_H
