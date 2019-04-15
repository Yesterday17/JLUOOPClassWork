//
// Created by t on 4/15.
//

#ifndef OOPCLASSWORK_ENCRYPT_H
#define OOPCLASSWORK_ENCRYPT_H

#include "../../week6/5/TRandom.h"
using Week6_5::TRandom;

namespace WEEK7_1 {
class Encrypt {
 public:
  static void Coder(unsigned char data[],int len, unsigned long key);
  static void Coder(unsigned char data[],int len, TRandom& rand, unsigned long key);
};
}
#endif //OOPCLASSWORK_ENCRYPT_H
