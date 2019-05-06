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
    }
});
