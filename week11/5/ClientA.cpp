//
// Created by Yesterday17 on 5/13.
//

#include <iostream>
#include "ClientA.h"
void WEEK11_5::ClientA::RequestA(WEEK11_5::Server &srv) {
  // cout << -----(5)----- << endl;
  std::cout << srv.Total(*this) << std::endl;
}
