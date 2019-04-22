#include <iostream>
#include <sstream>

#include "./menu/Menu.h"

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__TOS_WIN__) || defined(__WINDOWS__)
#include <windows.h>
class MBuf : public std::stringbuf {
 public:
  int sync() override {
    fputs(str().c_str(), stdout);
    str("");
    return 0;
  }
};
#endif

extern Menu *week6, *week7, *week8;

int main(int argc, char **argv) {
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__TOS_WIN__) || defined(__WINDOWS__)
  SetConsoleOutputCP(CP_UTF8);
  setvbuf(stdout, nullptr, _IONBF, 0);
  MBuf buf;
  std::cout.rdbuf(&buf);
#endif
  Clear();
  Menu *menu = new Menu(u8"OOP Homework", std::vector<Menu *>{
      week6, week7, week8
  });
  menu->Print();
  menu->Wait();

  std::cout << std::endl;
  getchar();
  return 0;
}