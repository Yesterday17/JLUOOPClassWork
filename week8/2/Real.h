//
// Created by Yesterday17 on 4/22.
//

#ifndef OOPCLASSWORK_REAL_H
#define OOPCLASSWORK_REAL_H

#include <string>
#include <vector>

namespace WEEK8_2 {

struct RealResult {
  int index;
  int part;
  std::string str;

  int numerator; // 分母
  int denominator; // 分子
  double value;
  double offset;
};

class Real {
 public:
  static const int MAXLEN = 30;

  explicit Real(double number, int stage = 0);
  RealResult &operator[](const unsigned int &r);

 private:
  int stage = 0;
  Real *next;
  double number;

  int part;
};
}

#endif //OOPCLASSWORK_REAL_H
