//
// Created by Yesterday17 on 5/13.
//

#include "ClientB.h"
int WEEK11_5::ClientB::CallBackFunc(int val) {
  return val * val;  // -----(6)-----;
  // 实现立方和将其改成 val * val * val 即可
}

void WEEK11_5::ClientB::RequestB(WEEK11_5::Server &srv) {
  std::cout << "平方和 = " << srv.Total(*this) << std::endl;  // -----(7)-----;
}