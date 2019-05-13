//
// Created by Yesterday17 on 5/13.
//

#include "Server.h"

int WEEK11_5::Server::Total(CallBackObject &obj) {
  int sum = 0;
  for (int i = 0; i < len; ++i) {
    sum += obj.CallBackFunc(this->data[i]); // -----(3)-----;
  }
  return sum;
}