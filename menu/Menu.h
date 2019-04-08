//
// Created by Yesterday17 on 4/8.
//
#ifndef OOPCLASSWORK_MENU_H
#define OOPCLASSWORK_MENU_H

#include <stdint.h>
#include <string>
#include <vector>
#include <functional>

void Clear();

struct MenuItem {
  std::string content;
  std::function<void()> callback;
};

class Menu {
 private:
  uint16_t now = 0;
  std::string title;
  bool LRMode = false;
  std::vector<MenuItem> items;
  std::vector<Menu*> menus;

  void Refresh(uint16_t i);
  void NLRPrint();
  void LRPrint();
  void GetCh2(char c);

 public:
  Menu(std::string title, std::vector<MenuItem> items);
  Menu(std::string title, std::vector<Menu*> menus);
  void Increase();
  void Decrease();
  void Reset();
  void Print();
  void Wait();
  void Execute();
};

#endif //OOPCLASSWORK_MENU_H
