//
// Created by Yesterday17 on 4/29.
//

#ifndef OOPCLASSWORK_WALL_H
#define OOPCLASSWORK_WALL_H
#include <iostream>

namespace WEEK9_3 {
class Wall {
 public:
  Wall() : color(0) { std::cout << "构造一面墙" << std::endl; }
  void Paint(int newColor) {
    color = newColor;
    std::cout << "用新颜色粉刷墙" << std::endl;
  }
  int GetColor() const { return color; }
 private:
  int color;
};
}

#endif //OOPCLASSWORK_WALL_H
