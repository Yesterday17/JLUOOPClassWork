//
// Created by Yesterday17 on 4/8.
//

#ifndef OOPCLASSWORK_WEEK6_PEN_H
#define OOPCLASSWORK_WEEK6_PEN_H
#include <stdint.h>
#include <iostream>
#define extends :

namespace Week6_4 {
class Color {
 private:
  uint8_t r = 0;
  uint8_t g = 0;
  uint8_t b = 0;
 public:
  Color() = default;
  Color(uint8_t r, uint8_t g, uint8_t b);
};

class BasePen {
 protected:
  Color color;
 public:
  explicit BasePen(Color color = Color(0, 0, 0));
};

class Pen extends BasePen {
 private:
  int64_t totalInk;
  int64_t nowInk;
 public:
  Pen();
  Pen(int64_t nowInk, int64_t totInk, Color color);

  /**
   * Write words, return whether ink is enough
   * @param text
   * @return
   */
  bool Write(std::string text);

  /**
   * Add Ink to pen, return exceed amount.
   * @param toAdd
   * @return
   */
  int AddInk(int64_t toAdd);
};
}
#endif //OOPCLASSWORK_WEEK6_PEN_H
