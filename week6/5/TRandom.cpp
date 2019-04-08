//
// Created by Yesterday17 on 4/8.
//

#include "TRandom.h"

namespace Week6_5 {
int TRandom::Next() {
  int loops = mSeed % 3;
  for (int i = 0; i <= loops; i++)
    Change();
  return int(mSeed / 2);
}

TRandom::TRandom(long seed) {
  mSeed = (seed ? seed : GetTickCount());
}
}
