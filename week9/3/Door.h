//
// Created by Yesterday17 on 4/29.
//

#ifndef OOPCLASSWORK_DOOR_H
#define OOPCLASSWORK_DOOR_H
#include <iostream>

namespace WEEK9_3 {
class Door {
 public:
  Door() : openOrClose(false) { std::cout << "构造一扇门" << std::endl; }
  void Open() {
    if (!IsOpened()) {
      openOrClose = true;
      std::cout << "门被打开了" << std::endl;
    } else {
      std::cout << "门开着呢！" << std::endl;
    }
  }
  void Close() {
    if (IsOpened()) {
      openOrClose = false;
      std::cout << "门被关上了" << std::endl;
    } else {
      std::cout << "门关着呢！" << std::endl;
    }
  }
  bool IsOpened() const { return openOrClose; }
 private:
  bool openOrClose;
};
}
#endif //OOPCLASSWORK_DOOR_H
