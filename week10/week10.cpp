//
// Created by Yesterday17 on 5/6.
//

#include <iostream>
#include "../menu/Menu.h"
#include "1/Walker.h"
#include "1/Thief.h"
#include "2/Policeman.h"
#include "2/PoliceStation.h"
#include "3/3.h"
#include "4/Woman.h"
#include "5/B.h"
#include "6/NewA.h"
#include "8/Paginate.h"

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
    },
    {
        u8"Policeman & PoliceStation",
        []() {
          WEEK10_2::PoliceStation station;
          station.AddPoliceman("p1");
          station.AddPoliceman("p2");
          station.AddPoliceman("p3");

          WEEK10_1::Thief t1(500), t2(800), t3(300), t4(1000);
          station.getPoliceman("p1")->catchThief(t2);
          station.getPoliceman("p1")->catchThief(t3);
          station.getPoliceman("p2")->catchThief(t4);

          station.PrintReport();
        }
    },
    {
        u8"Thief & Walker & Policeman & PoliceStation",
        []() {
          WEEK10_3::main();
        }
    },
    {
        u8"Man & Woman",
        []() {
          WEEK10_4::Woman wo1("WO1"), wo2("WO2");
          WEEK10_4::Man m1("M1"), m2("M2");

          wo1.marry(&m2);
          wo1.marry(&m1);
          wo1.divorce();
        }
    },
    {
        u8"引用计数",
        []() {
          {
            WEEK10_5::B data(10);
            std::cout << "Num: " << data->GetData() << std::endl;
            {
              WEEK10_5::B c(data);
              {
                WEEK10_5::B d;
                d = data;
              }
            }
          }
          WEEK10_5::B data(10);
          data.SetData(20);
        }
    },
    {
        u8"new/delete 计数",
        []() {
          auto a1 = new WEEK10_6::NewA();
          auto a2 = new WEEK10_6::NewA();
          auto a3 = new WEEK10_6::NewA[10]();
          delete a1;
          delete a2;
          delete[] a3;
        }
    },
    {
        u8"理解重载运算符的函数形式",
        []() {
          std::cout << "> 为什么重载 `+`，一般用自由函数形式？\n"
                       "因为 `+` 后类型不确定。\n\n"
                       "> 为什么重载 `+=`，一般用成员函数形式？\n"
                       "因为 `+=` 后类型一般和原类型一致。\n\n"
                       "> 为什么重载 `=`，必须用成员函数形式？\n"
                       "因为赋值时需要保证左操作数可改，不能出现诸如 `6 = a` 的情况。\n\n"
                       "> 为什么重载 `<<`，必须用自由函数形式？"
                       "因为在 `<<` 时左值不一定为变量本身。\n\n" << std::endl;
        }
    },
    {
        u8"分页器类",
        []() {
          WEEK10_8::Paginate pager(1, 13);
          for (int i = 1; i <= 13; ++i) {
            // i当前页，13总页数
            pager.setPage(i, 13).show();
          }
          std::cout << "start move...." << std::endl;
          pager.setPage(5, 13).show();
          pager.next().show();
          pager.prev().show();

          // 直接翻5页
          pager.nextN().show();
          pager.next().show();
          pager.prevN().show();
        }
    }
});
