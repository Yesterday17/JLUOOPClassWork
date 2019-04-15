//
// Created by t on 4/15.
//

#include "encrypt.h"
void WEEK7_1::Encrypt::Coder(unsigned char *data, int len, unsigned long key) {
  TRandom rand(key);
  for (int i = 0;i<len;i++) {
    data[i] = data[i] ^ rand.Integer();
  }
}
void WEEK7_1::Encrypt::Coder(unsigned char *data, int len, TRandom &rand, unsigned long key) {
  rand.Seed(key);
  for (int i = 0;i<len;i++) {
    data[i] = data[i] ^ rand.Integer();
  }
}
