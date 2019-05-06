//
// Created by Yesterday17 on 5/6.
//

#ifndef OOPCLASSWORK_NEWA_H
#define OOPCLASSWORK_NEWA_H

#include <cstddef>
#include <iostream>
namespace WEEK10_6 {
class NewA {
 private:
  inline static int news = 0;
  inline static int deletes = 0;
 public:
  void *operator new(std::size_t sz) {
    news++;
    std::cout << "new: " << news << std::endl;
    return ::operator new(sz);
  }
  void *operator new[](std::size_t sz) {
    news++;
    std::cout << "new[]: " << news << std::endl;
    return ::operator new[](sz);
  }

  void operator delete(void *ptr) {
    deletes++;
    std::cout << "delete: " << deletes << std::endl;
    ::operator delete(ptr);
  }

  void operator delete[](void *ptr) {
    deletes++;
    std::cout << "delete[]: " << deletes << std::endl;
    ::operator delete[](ptr);
  }
};
}

#endif //OOPCLASSWORK_NEWA_H
