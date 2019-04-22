//
// Created by Yesterday17 on 4/22.
//

#include <iostream>
#include "A.h"

void WEEK8_4::g(int n) {
  auto **arr = new WEEK8_4::A *[n];
  for (int i = 0; i < n; i++) {
    arr[i] = new WEEK8_4::A(i + 1);
    std::cout << "arr[" << i << "].Data() = " << arr[i]->Data() << std::endl;
  }

  for (int i = 0; i < n; i++)
    delete arr[i];
  delete[] arr;
}
