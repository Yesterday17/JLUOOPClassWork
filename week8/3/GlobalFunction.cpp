//
// Created by Yesterday17 on 4/22.
//

#include <iostream>
#include "GlobalFunction.h"

void WEEK8_3::f(int n, int m) {
  std::cout << std::endl;
  // malloc
  int **arr = new int *[n];

  // assign
  for (int i = 0; i < n; i++) {
    arr[i] = new int[m];
    int tot = 0;
    for (int j = 0; j < m; j++) {
      arr[i][j] = (i + 1) * (j + 1);
      tot += arr[i][j];
    }
    std::cout << "第" << i + 1 << "行之和为: " << tot << std::endl;
  }

  // print array
  std::cout << std::endl << "数组如下: " << std::endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cout << arr[i][j] << "\t";
    }
    std::cout << std::endl;
  }

  // free
  for (int i = 0; i < n; i++)
    delete arr[i];
  delete[] arr;
}
