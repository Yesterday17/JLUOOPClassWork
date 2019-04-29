//
// Created by Yesterday17 on 4/29.
//

#ifndef OOPCLASSWORK_YETANOTHERWALLWITHDOOR_H
#define OOPCLASSWORK_YETANOTHERWALLWITHDOOR_H

#include "IBaseWallWithDoor.h"
#include "Wall.h"
#include "Door.h"

namespace WEEK9_3 {
/**
 * 这里为了在主函数中调用方便 implement 了 IBaseWallWithDoor 接口
 * 本质为单继承
 */
class YetAnotherWallWithDoor : private Wall, public IBaseWallWithDoor {
 private:
  Door door;
 public:
  void PaintWall(int newColor) override {
    Paint(newColor);
    switch (newColor) {
      case 0: // green
        door.Open();
        break;
      case 1: // red
        door.Close();
        break;
      default:std::cout << "门的状态不变" << std::endl;
    }
  }
};
}

#endif //OOPCLASSWORK_YETANOTHERWALLWITHDOOR_H
