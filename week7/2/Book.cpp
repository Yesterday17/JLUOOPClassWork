//
// Created by Yesterday17 on 4/15.
//

#include "Book.h"
void Week7_2::Book::nextPage() {
  nowPage++;
}
void Week7_2::Book::PrevPage() {
  nowPage--;
}
uint64_t Week7_2::Book::getPage() {
  return nowPage;
}
uint64_t Week7_2::Book::todayRead() {
  return todayPagesRead;
}
uint64_t Week7_2::Book::totalRead() {
  return totalPagesRead;
}
uint64_t Week7_2::Book::unreadPages() {
  return totalPages - nowPage;
}
