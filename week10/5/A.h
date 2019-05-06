//
// Created by Yesterday17 on 5/6.
//

#ifndef OOPCLASSWORK_WEEK10_5_A_H
#define OOPCLASSWORK_WEEK10_5_A_H

namespace WEEK10_5 {
class A {
 public:
  explicit A(int num) : mData(num) {}
  ~A() = default;
  int GetData() const { return mData; }
  void SetData(int data) { mData = data; }
 private:
  int mData;
};
}

#endif //OOPCLASSWORK_WEEK10_5_A_H
