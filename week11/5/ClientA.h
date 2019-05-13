//
// Created by Yesterday17 on 5/13.
//

#ifndef OOPCLASSWORK_CLIENTA_H
#define OOPCLASSWORK_CLIENTA_H

#include "CallBackObject.h"
#include "Server.h"

namespace WEEK11_5 {
class ClientA : public CallBackObject {
 public:
  virtual ~ClientA() = default;
  virtual int CallBackFunc(int val) {
    return val;
  }
  void RequestA(Server &srv);
};
}

#endif //OOPCLASSWORK_CLIENTA_H
