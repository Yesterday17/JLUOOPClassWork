//
// Created by Yesterday17 on 4/22.
//

#ifndef OOPCLASSWORK_MYSTRING_H
#define OOPCLASSWORK_MYSTRING_H

namespace WEEK8_1 {

class MyString {
 public:
  explicit MyString(const char *pData = nullptr);    // 普通构造函数
  MyString(const MyString &);            // 拷贝构造函数
  ~ MyString();          // 析构函数
  MyString &operator=(const MyString &) noexcept;  // 赋值函数
  MyString &operator+=(const MyString &);
  explicit operator char *() const;                   // 自动转换函数
 private:
  char *mpData;        // 用于保存字符串
};

}

#endif //OOPCLASSWORK_MYSTRING_H
