//
// Created by Yesterday17 on 5/6.
//

#include <iostream>
#include "../menu/Menu.h"
#include "1/Walker.h"
#include "1/Thief.h"

Menu *week10 = new Menu(u8"面向对象程序设计上机练习（五）", std::vector<MenuItem>{
    {
        u8"Thief & Walker",
        []() {
          WEEK10_1::Walker a(100), b(20);
          WEEK10_1::Thief f;

          std::cout << "A: ";
          a.printMoney();

          std::cout << std::endl << "B: ";
          b.printMoney();

          std::cout << std::endl << "f.steal(a), A: ";
          f.steal(a);
          a.printMoney();
          std::cout << std::endl << "F: ";
          f.printMoney();

          std::cout << std::endl << "f.steal(b), B: ";
          f.steal(b);
          b.printMoney();
          std::cout << std::endl << "F: ";
          f.printMoney();
        }
    }
});
