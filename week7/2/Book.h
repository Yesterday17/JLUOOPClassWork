//
// Created by Yesterday17 on 4/15.
//

#ifndef OOPCLASSWORK_BOOK_H
#define OOPCLASSWORK_BOOK_H

#include <stdint.h>
namespace Week7_2 {
class Book {
 private:
  uint64_t totalPages;
  uint64_t nowPage;
  uint64_t totalPagesRead;
  uint64_t todayPagesRead;
 public:
  void nextPage();
  void PrevPage();
  uint64_t getPage();
  uint64_t todayRead();
  uint64_t totalRead();
  uint64_t unreadPages();
};
}
#endif //OOPCLASSWORK_BOOK_H
