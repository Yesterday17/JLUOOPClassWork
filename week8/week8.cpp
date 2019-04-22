//
// Created by Yesterday17 on 4/22.
//

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include "../menu/Menu.h"

#include "./2/Real.h"

using WEEK8_2::Real;
Menu *week8 = new Menu(u8"面向对象程序设计上机练习（三）", std::vector<MenuItem>{
    {
        u8"字符串类",
        []() {}
    },
    {
        u8"连分数类",
        []() {
          Real r = Real(M_PI);
          std::cout << std::setprecision(16);

          for (int i = 0; i < 10; i++) {
            auto ans = r[i];
            std::cout << "前" << ans.index << "项为" << ans.str << std::endl;
            std::cout << "前" << ans.index << "项对应分数为" << ans.denominator << "/" << ans.numerator << std::endl;
            std::cout << "前" << ans.index << "项对应分数的值为" << ans.value << std::endl;
            std::cout << "前" << ans.index << "项对应分数与" << M_PI << "的差为" << ans.offset << std::endl;
          }
        }
    }
});