//
// Created by Yesterday17 on 4/15.
//

#include "../menu/Menu.h"
#include "./1/encrypt.h"
#include <iostream>
#include <string>
using WEEK7_1::Encrypt;

Menu *week7 = new Menu(u8"面向对象程序设计上机练习（二）", std::vector<MenuItem>{
    {
        u8"加密解密",
        []() {
          unsigned char str[] = {'a', 'b', 'c', 'd', 'e', '\0'};
          Encrypt enc;
          TRandom rnd;

          std::cout << u8"原字符串：" << str << std::endl;
          for (int i = 0; i < 5; i++)std::cout << (int) str[i] << " ";
          std::cout << std::endl;

          enc.Coder(str, 5, (unsigned long) 10);
          std::cout << u8"加密后：" << str << std::endl;
          for (int i = 0; i < 5; i++)std::cout << (int) str[i] << " ";
          std::cout << std::endl;

          enc.Coder(str, 5, rnd, (unsigned long) 10);
          std::cout << u8"解密后：" << str << std::endl;
          for (int i = 0; i < 5; i++)std::cout << (int) str[i] << " ";
          std::cout << std::endl;

          std::cout << "3. 结果未改变，传值与否此处结果相同。" << std::endl;
          std::cout << std::endl;

          std::cout << "4. 无法通过编译。" << std::endl;
          std::cout << std::endl;

          std::cout << "5. 见代码" << std::endl;
          std::cout << std::endl;
        },
        {
          u8"Book 类",
          [](){
            std::cout << "5. 见代码" << std::endl;
            std::cout << std::endl;
          }
        },
        {
          u8"Card 类",
          [](){
            //
          }
        }
    }
});