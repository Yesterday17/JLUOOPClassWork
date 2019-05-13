//
// Created by Yesterday17 on 5/13.
//

#ifndef OOPCLASSWORK_CLIENTB_H
#define OOPCLASSWORK_CLIENTB_H

#include <iostream>
#include "CallBackObject.h"
#include "Server.h"
namespace WEEK11_5 {
class ClientB : public CallBackObject {
 public:
  virtual ~ClientB() {}
  virtual int CallBackFunc(int val);
  void RequestB(Server &srv);
};
}

#endif //OOPCLASSWORK_CLIENTB_H
