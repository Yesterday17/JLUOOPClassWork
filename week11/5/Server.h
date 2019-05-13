//
// Created by Yesterday17 on 5/13.
//

#ifndef OOPCLASSWORK_SERVER_H
#define OOPCLASSWORK_SERVER_H

#include "CallBackObject.h"
namespace WEEK11_5 {
class Server {
 public:
  Server(int size) : len(size) {
    this->data = new int[len]; // -----(1)-----;

    for (int i = 0; i < len; ++i)
      data[i] = i + 1;
  }
  ~Server() {
    delete this->data; // ----(2)-----;
  }
  int Total(CallBackObject &obj);
 private:
  int len;
  int *data;
};
}

#endif //OOPCLASSWORK_SERVER_H
