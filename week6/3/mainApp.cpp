//
// Created by Yesterday17 on 4/8.
//
#include <iostream>
#include "a.h"
#include "b.h"

namespace Week6_3 {
/**
 * Question 1
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[]) {
  A aA;

  if (argc > 1) {
    aA.Display(argv[1]);
  } else {
    aA.Display();
  }

  std::cout << sizeof(A) << std::endl;

  return 0;
}

/**
 * Question 2
 * @param str
 * @param flag1
 * @param flag2
 */
void A::Display(const char *str, bool flag1, bool flag2) const {
  std::cout << "The argment is " << str << std::endl;
}

/**
 * Question 2.1
 * @param argc
 * @param argv
 * @return
 */
int main_inline(int argc, char *argv[]) {
  A aA;

  if (argc > 1) {
    aA.Display(argv[1], true);
  } else {
    aA.Display();
  }

  std::cout << sizeof(A) << std::endl;
  return 0;
}

/**
 * Question 2.2
 * @param argc
 * @param argv
 * @return
 */
int main_outer(int argc, char *argv[]) {
  A aA;

  if (argc > 1) {
    aA.Display(argv[1], true, true);
  } else {
    aA.Display();
  }

  std::cout << sizeof(A) << std::endl;
  return 0;
}

/**
 * Question 4
 * @param argc
 * @param argv
 * @return
 */
int main_variable_declare(int argc, char **argv) {
  A aA;
  aA.getAStaticInt();
  aA.getAStaticArray();

  return 0;
}

void BB::Func2() {
  std::cout << "This is member function Func()" << std::endl;
}

}