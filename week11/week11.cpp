//
// Created by Yesterday17 on 5/13.
//

#include <iostream>
#include <asptlb.h>
#include "../menu/Menu.h"
#include "1/A.h"
#include "1/B.h"
#include "2/Monster.h"
#include "3/Cat.h"
#include "3/Dog.h"
#include "4/Box.h"
#include "5/ClientA.h"
#include "5/ClientB.h"

Menu *week11 = new Menu(u8"面向对象程序设计上机练习（六）", std::vector<MenuItem>{
    {
        u8"阅读并执行代码,然后回答问题",
        []() {
          std::cout << "1. 去掉 virtual 后 B 的析构函数不会被执行，只执行了 A 的析构函数（由于*p的类型为A）。" << std::endl;
          std::cout << "2. 不可以，override 的类型必须和基类匹配。" << std::endl;
          std::cout << "3. 匹配的是(3)的初始值，说明初始值是静态绑定的。" << std::endl;
          std::cout << "4. 不可以，改为 private 后继承类B中就无法使用该属性了。" << std::endl;
          std::cout << "5. 没有。" << std::endl;
          std::cout << "6. (9)的作用是给静态成员变量赋初始值。" << std::endl;
          std::cout << "7. 不可以，抽象类含有纯虚函数，无法实例化。" << std::endl;
          std::cout << "8. 若仅删去virtual，无法通过编译（由于=0）；若同时删除=0，无法通过编译（由于函数体不存在）；如果加上函数体，编译成功，且调用时调用A中的Func2。" << std::endl;
          std::cout << "9. 在A中不存在Func3；仍然不可以。" << std::endl;
          std::cout << "10. (15)尝试向参数列表为[]的函数传入一个参数。" << std::endl;

          std::cout << std::endl << "以下为原始执行结果：" << std::endl;
          WEEK11_1::A *p = new WEEK11_1::B;
          //---------------------------------------------(10)

          p->Func2(50);
          //---------------------------------------------(11)

          p->Func2();
          //---------------------------------------------(12)

          p->Func1();
          //---------------------------------------------(13)

          // p->Func3(100);
          //---------------------------------------------(14)

          // p->Func1(100);
          //---------------------------------------------(15)
          delete p;
          return 0;
        }
    },
    {
        u8"Monster",
        []() {
          WEEK11_2::Monster a, b;
          a.fight(b);
        }
    },
    {
        u8"Cat & Dog",
        []() {
          WEEK11_3::Cat a;
          WEEK11_3::Dog b;
          a.fight(b);
        }
    },
    {
        u8"水果盒子",
        []() {
          WEEK11_4::Box box;
          box.addFruit(false);
          box.addFruit(false);
          box.addFruit(true);
          std::cout << "目前总重量为：" << box.totWeight() << std::endl;
          box.newDay();
          std::cout << "目前总重量为：" << box.totWeight() << std::endl;
          box.addFruit(false);
          box.addFruit(true);
          std::cout << "目前总重量为：" << box.totWeight() << std::endl;
          box.newDay();
          box.newDay();
          std::cout << "目前总重量为：" << box.totWeight() << std::endl;
          box.newDay();
          box.newDay();
          box.newDay();
          box.newDay();
          box.newDay();
          std::cout << "目前总重量为：" << box.totWeight() << std::endl;
        }
    },
    {
        u8"Client & Server",
        []() {
          {
            // main1
            std::cout << "Main 1" << std::endl;
            WEEK11_5::Server srv2(2), srv5(5);
            WEEK11_5::ClientA a;
            a.RequestA(srv2);  //输出3
            a.RequestA(srv5);  //输出15
            std::cout << std::endl;
          }
          {
            // main2
            std::cout << "Main 2(1)" << std::endl;
            WEEK11_5::Server srv2(2), srv3(3);
            WEEK11_5::ClientB b;
            b.RequestB(srv2);
            b.RequestB(srv3);
          }
          {
            // main2
            std::cout << "Main 2(2)" << std::endl;
            std::cout << "立方和见(6)处注释" << std::endl;
          }
        }
    }
});
