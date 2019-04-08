//
// Created by Yesterday17 on 4/8.
//

#ifndef OOPCLASSWORK_Week6_TRANDOM_H
#define OOPCLASSWORK_Week6_TRANDOM_H

#include <limits.h>   // 声明INT_MAX和ULONG_MAX常量
#include <windows.h>  // 声明GetTickCount()函数，其返回从开机到现在经过的毫秒数
// #include <stdlib.h>   // 声明rand和srand函数
// #include <time.h>     // 声明time函数

namespace Week6_5 {
class TRandom {
 public:
  // 缺省使用系统时间(开机后经过的毫秒数)为种子
  explicit TRandom(long seed = 0) ;

  // 也可以定义自己的种子
  void Seed(long seed = 0) {
    mSeed = (seed ? seed : GetTickCount());
  }

  // 取得一个随机的整数
  int Integer() {
    return Next();
  }

  // 取得一个在指定范围内的随机整数
  int Integer(int min, int max) {
    return min + Next() % (max - min + 1);
  }

  // 取得一个随机的（0到1之间的）小数
  double Real() {
    return double(Next()) / double(INT_MAX);
  }

 private:
  // 使用调和算法
  void Change() {
    mSeed = (314159265 * mSeed + 13579) % ULONG_MAX;
  }

  // 取得伪随机数发生器的随机数序列中的下一个随机整数
  int Next();
  unsigned long mSeed;  // 随机数发生器的种子
};
}
#endif //OOPCLASSWORK_Week6_TRANDOM_H
