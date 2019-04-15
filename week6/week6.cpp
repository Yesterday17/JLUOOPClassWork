//
// Created by t on 4/8.
//
#include <iostream>

#include "1/Header.h"
#include "3/Header.h"
#include "5/TRandom.h"
#include "6/Dice.h"
#include "../menu/Menu.h"

Menu *week6 = new Menu(u8"面向对象程序设计上机练习（一）", std::vector<MenuItem>{
    {
        u8"源文件与头文件的关系",
        []() {
          Week6_1::main();
        }
    },
    {
        u8"重载函数与等价函数的实验",
        []() {
          std::cout << u8"int max(int, int);\n"
                       u8"int max(const int, const int);\n"
                       u8"const int max(int, int); // 上三者等价\n"
                       u8"int max(int&, int&);\n"
                       u8"const int& max(int&, int&); // 上二者等价\n"
                       u8"int& max(const int&, const int&);\n"
                       u8"const int& max(const int&, const int&); "
                       u8"int& max(int&, int&);// 上三者等价\n" << std::endl;
        }
    },
    {
        u8"练习类的定义与多文件实现",
        []() {
          std::cout << u8"1. 执行结果：" << std::endl;
          Week6_3::main(__argc, __argv);

          std::cout << std::endl;

          std::cout << u8"2. inline/纯外联" << std::endl;
          std::cout << u8"2.1 inline" << std::endl;
          Week6_3::main_inline(__argc, __argv);
          std::cout << u8"2.2 纯外联" << std::endl;
          Week6_3::main_outer(__argc, __argv);

          std::cout << std::endl;

          std::cout << u8"3. 写或不写包含警戒程序均正确执行(因为只存在一次引用)" << std::endl;

          std::cout << std::endl;

          std::cout << u8"4. 执行结果" << std::endl;
          Week6_3::main_variable_declare(__argc, __argv);

          std::cout << std::endl;

          std::cout << u8"5. 调用B中成员函数Func" << std::endl;
          Week6_3::B b;
          b.Func();

          std::cout << std::endl;

          std::cout << u8"6. 此时不写包含警戒程序无法正确执行(因为出现了多次引用)" << std::endl;

          std::cout << std::endl;

          std::cout << u8"7. 修改B类" << std::endl;
          Week6_3::A a;
          Week6_3::BB bb(a);
          bb.Func();

          std::cout << std::endl;

          std::cout << u8"8. 外联实现B::Func" << std::endl;
          bb.Func2();
          std::cout << u8"#include 会将整个头文件从头到尾包括，而 class A; 只是声明存在 class A" << std::endl;
        }
    },
    {
        u8"练习将实际生活中的事物，抽象成类，并给出类的设计",
        []() {
          std::cout << u8"见代码实现。" << std::endl;
        }
    },
    {
        u8"练习读懂类的代码，练习使用已有的类",
        []() {
          Week6_5::TRandom random;
          int arr[54];
          std::cout << u8"4.1 原牌堆: " << std::endl;
          for (int i = 0; i < 54; i++) {
            arr[i] = i;
            std::cout << arr[i] << " ";
          }
          std::cout << std::endl;

          auto swap = [&arr](int i, int j) {
            int k = arr[i];
            arr[i] = arr[j];
            arr[j] = k;
          };

          for (int i = 0; i < 100; i++) {
            swap(random.Integer(0, 53), random.Integer(0, 53));
          }

          std::cout << u8"现牌堆: " << std::endl;
          for (auto i : arr) {
            std::cout << i << " ";
          }
          std::cout << std::endl;

          std::cout << std::endl;

          std::cout << u8"4.2 计算 PI" << std::endl;
          double in = 0, tot = 10000000;
          for (int i = 0; i < tot; i++) {
            double x = random.Real(), y = random.Real();
            if (x * x + y * y <= 1.0)in++;
          }

          std::cout << u8"PI = " << (in * 4.0 / tot) << std::endl;
        }
    },
    {
        u8"骰子类",
        []() {
          Week6_6::Dice dice;
          std::cout << "当前点数: " << dice.Roll() << std::endl;
          std::cout << "底部点数: " << dice.Bottom() << std::endl;
          std::cout << "投掷 5 个骰子的结果: " << dice.Roll(5) << std::endl;
        }
    }
});