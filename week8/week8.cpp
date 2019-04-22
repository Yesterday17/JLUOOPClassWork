//
// Created by Yesterday17 on 4/22.
//

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include "../menu/Menu.h"

#include "2/Real.h"
#include "3/GlobalFunction.h"
#include "4/A.h"

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
    },
    {
        u8"二维数组动态分配",
        []() {
          std::cout << "数组大小: 10*15" << std::endl;
          WEEK8_3::f(10, 15);
        }
    },
    {
        u8"指向A类对象的一维指针数组",
        []() {
          WEEK8_4::g(10);
        }
    }
});