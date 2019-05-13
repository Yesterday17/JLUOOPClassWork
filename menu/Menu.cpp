//
// Created by Yesterday17 on 4/8.
//

#include <iostream>
#include <conio.h>
#include "Menu.h"

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__TOS_WIN__) || defined(__WINDOWS__)
void Clear() {
  system("cls");
}
#else
void Clear() {
  std::cout << "\033[2J\033[1;1H";
}
#endif

Menu::Menu(const char *title, std::vector<MenuItem> items) {
  this->title = title;
  this->items = items;
}

Menu::Menu(const char *title, std::vector<Menu *> menus) {
  this->title = title;
  this->menus = menus;
  this->LRMode = true;
}

void Menu::LRPrint() {
  this->menus.at(this->now)->Print();
}

void Menu::NLRPrint() {
  std::cout << this->title << std::endl;
  for (auto i = items.begin(); i != items.end(); i++) {
    std::cout << u8"(" << (this->now == i - items.begin() ? u8"*" : u8" ") << u8")"
              << i - items.begin() + 1 << u8". " << i->content << std::endl;
  }
}

void Menu::Print() {
  if (this->LRMode)
    this->LRPrint();
  else
    this->NLRPrint();
}

void Menu::Refresh(uint16_t i) {
  this->now = i;
  this->Print();
}

void Menu::Reset() {
  this->now = 0;
  this->Print();
}

void Menu::Increase() {
  if ((this->LRMode && this->now < this->menus.size() - 1) || (!this->LRMode && this->now < this->items.size() - 1)) {
    this->now++;
  } else {
    this->now = 0;
  }
  Clear();
  this->Print();
}

void Menu::Decrease() {
  if (this->now > 0) {
    this->now--;
  } else {
    if (this->LRMode) {
      this->now = this->menus.size() - 1;
    } else {
      this->now = this->items.size() - 1;
    }
  }
  Clear();
  this->Print();
}

void Menu::Wait() {
  while (true) {
    char c = getch();
    if (c == -32) {
      c = getch();
      this->GetCh2(c);
    } else if (c == 13) {
      // ENTER
      Clear();
      this->Execute();
      break;
    }
  }
}

void Menu::GetCh2(char c) {
  switch (c) {
    case 72:
      // UP
      if (!this->LRMode)
        this->Decrease();
      else
        this->menus.at(this->now)->GetCh2(c);
      break;

    case 80:
      // DOWN
      if (!this->LRMode)
        this->Increase();
      else
        this->menus.at(this->now)->GetCh2(c);
      break;

    case 75:
      // LEFT
    case 73:
      // PGUP
      if (this->LRMode) {
        this->Decrease();
      }
      break;

    case 77:
      // RIGHT
    case 81:
      // PGDN
      if (this->LRMode) {
        this->Increase();
      }
      break;
    default:break;
  }
}

void Menu::Execute() {
  if (this->LRMode) {
    this->menus.at(this->now)->Execute();
  } else {
    Clear();
    std::cout << this->items.at(this->now).content << std::endl;
    this->items.at(this->now).callback();
  }
}