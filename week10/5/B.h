//
// Created by Yesterday17 on 5/6.
//

#ifndef OOPCLASSWORK_WEEK10_5_B_H
#define OOPCLASSWORK_WEEK10_5_B_H

#include "A.h"
namespace WEEK10_5 {
class Ptr {
 private:
  explicit Ptr(int num = 0) : pa(new A(num)), count(1) {}
  explicit Ptr(A *a) : pa(a), count(1) {}
  ~Ptr() { delete pa; };
  friend class B;
  int count;
  A *pa;
};

class B {
 public:
  explicit B(int num = 0);
  explicit B(const B &rhs) : ptr(rhs.ptr) { ++ptr->count; };
  ~B();

  B &operator=(const B &rhs) {
    rhs.ptr->count++;
    if (--this->ptr->count == 0) {
      delete this->ptr;
    }
    this->ptr = rhs.ptr;
    return *this;
  }

  A *operator->() const { return ptr->pa; }
  int GetData() const { return ptr->pa->GetData(); }
  void SetData(int data) { ptr->pa->SetData(data); }
 private:
  Ptr *ptr;
  void detach();
};
}

#endif //OOPCLASSWORK_WEEK10_5_B_H
