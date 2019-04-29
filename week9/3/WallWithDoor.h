//
// Created by Yesterday17 on 4/29.
//

#ifndef OOPCLASSWORK_WALLWITHDOOR_H
#define OOPCLASSWORK_WALLWITHDOOR_H

#include "Door.h"
#include "Wall.h"
#include "IBaseWallWithDoor.h"
namespace WEEK9_3 {
class WallWithDoor : private Door, private Wall, public IBaseWallWithDoor {
 public:
  void PaintWall(int newColor) override {
    Paint(newColor);
    switch (newColor) {
      case 0: // green
        Open();
        break;
      case 1: // red
        Close();
        break;
      default:std::cout << "门的状态不变" << std::endl;
    }
  }
};
}

#endif //OOPCLASSWORK_WALLWITHDOOR_H
