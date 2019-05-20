# 1

为每个 cpp 文件都写一个对应的头文件,其中放置对应的 cpp 文件中的需要向外部公开的函数声明或变量声明、常量声明，最好使用包含警戒。
本例子中 mymain.cpp 中由于只有一个 main 函数(main 函数是默认的入口函数)，可以不写 mymain.h.
其它：
与 `Func1.cpp` 对应的 `func1.h`

```cpp
#ifndef FUNC1H
#deinfe FUNC1H
int f1(int num);
#endif
```

与 `Func2.cpp` 对应的 `func2.h`

```cpp
#ifndef FUNC2H
#deinfe FUNC2H
int g1(int num);
int g2(int num);
#endif
```

若某个 `cpp` 文件中需要访问其它 `cpp` 中的函数，只需在其中 `include` 相应的头文件
如：`func2.cpp` 中用到 `f1` 函数，需在 `func2.cpp` 中加入 `#include "func1.h"`

对于常数/枚举常数，也可放在一个单独的头文件中，如 global.h,哪个 cpp 中要用到这些常量，就在其中 `#include "global.h"`。

```cpp
#ifndef GLOBALH
#deinfe GLOBALH
const int YEARDAYS=365;
const enum WEEKDAY {MON=1,TUE,WED,THU,FRI,SAT,SUN};
#endif
```

```cpp
//mymain.cpp
#include <iostream.h>
#include "func2.h"
int main(int argc,char * argv[]) {
  cout << g2(10) << endl;
  return 0;
}
```

```cpp
//func1.cpp
#include "func1.h"
#include "func2.h"
int f1(int num) {
  return g1(num*2);
}
```

```cpp
//func2.cpp
#include "func1.h"
#include "func2.h"
int g1(int num) {
    return num*num;
}

int g2(int num) {
  return f1(num*3);
}
```

# 5

```cpp
#include <limits.h>  //定义INT_MAX和ULONG_MAX常量
#include <windows.h>  //定义GetTickCount()函数,其返回从开机到现在经过的毫秒数
class TRandom {  public:
    TRandom (long seed=0)    {mSeed=(seed?seed: GetTickCount()); }
    void Seed(long seed=0)    {mSeed=(seed?seed: GetTickCount());}
    int  Integer()  {return Next();}
    int  Integer(int min,int max)   {return min+Next()%(max-min+1);}
    double Real()   {return double(Next())/double(INT_MAX);}
  private:
    void Change()     {mSeed=(314159265*mSeed+13579)%ULONG_MAX;}
    int  Next()   { int loops=mSeed%3;  for (int i=0;i<=loops;i++)  Change ();
        return int (mSeed/2); }
    unsigned long  mSeed;
};
```

```cpp
int main() {
  int cards[54];
  for(int i=0;i<54;++i)
    cards[i]=i+1;

  TRandom rand;   //创建伪随机数发生器的一个实例对象

  //以下是洗牌过程
  for(int j=0;j<54;++j) {
    int pos=rand.Integer(j,53); //pos是一个[j,53]之间的随机数

    //交换cards[j]和cards[pos];
    int temp=cards[j];
    cards[j]=cards[pos];
    cards[pos]=temp;
  }

  //输出洗牌结果
  for (int k=0;k<54;++k)
    cout<<"Cards["<<k<<"]="<<cards[k]<<endl;

  return 0;
}
```

采用伪随机数洗牌，无论洗多少张牌，排列的可能都是`2`的`32`次方种可能。因为伪随机数发生器给定，应用的算法给定，对指定的种子(`seed`),产生的伪随机数数列就确定了，也就是洗牌后的结果定了。而在`32`位平台上，`seed` 是无符号长整形，最多有`2`的`32`次方种可能，它远远小于`54!`。这也是商业加密算法不使用伪随机数加密的原因。

# 6

```cpp
// Dice.h

#ifndef DICEH
#define DICEH

class Dice {
public:
  static const enum SIDE {FRONT =0,LEFT,TOP,RIGHT,BOTTOM,BACK  };
  static const char * Names[];//在Cpp文件中初始化
public:
  Dice();
  int  Cast();
  int  FaceValue(SIDE side) const;  //返回指定面的值
private:
  void Turn();
  void TurnX();
  void TurnY();
  void TurnZ();
private:
  int  values[6];
};

#endif
```

```cpp
//dice.cpp
#include <iostream.h>
#include <stdlib.h>  //用于随机函数:randomize()和random(num)、rand()
#include <time.h>

//---------------------------------------------------------------------------
//  本例是在BCB6.0中编译通过的。
//  在VC6.0下，需做部分修改。其中随机数函数使用的例子如下：
//  void srand(unsigned long seed );     功能：设置随机数发生器的种子。
//  int  rand();      功能：返回0到2的32次方的一个伪随机整数
//  例：
//  #include <iostream.h>
//  #include <stdlib.h>
//  #include <time.h>

//  int main(void)
//  {
//  time_t t;
//  srand((unsigned) time(&t));  //此句用系统时间作为种子。

//  cout<<"Ten random numbers from 0 to 99")<<endl;
//  for(int i=0; i<10; i++)
//    cout<< rand() % 100 <<endl;
//  return 0;
//  }

#include "dice.h"

//初始化Names数组
const char * Dice::Names[] = {"FRONT","LEFT","TOP","RIGHT","BOTTOM","BACK"};

Dice::Dice() {
  values[FRONT] = 1;
  values[TOP]   = 2;
  values[RIGHT] = 3;
  values[LEFT]  = 4;
  values[BOTTOM]= 5;
  values[BACK]  = 6;

  randomize();  //初始化随机数发生器，也可放在入口函数main中。
  //srand(time(0));  // VC6.0中可这样使用
}

int Dice::Cast() {
  Turn();
  return FaceValue(FRONT);
}

void Dice::Turn() {
  //取得0－3的随机数:可用random(4) 或 rand()%4
  int num;
  num = random(4);  //取得0－3的随机数
  //num = rand()%4; VC6.0中改为这条语句
  for(int i=0;i<num;i++)
    TurnX();

  num = random(4);  //取得0－3的随机数
  //num = rand()%4; VC6.0中改为这条语句
  for(int i=0;i<num;i++)
    TurnY();

  num = random(4);  //取得0－3的随机数
  //num = rand()%4; VC6.0中改为这条语句
  for(int i=0;i<num;i++)
    TurnZ();
}

int Dice::FaceValue(SIDE side) const {
  return values[side];
}

//按X轴旋转90度
void Dice::TurnX() {
  int temp   = values[FRONT];
  values[FRONT]  = values[TOP];
  values[TOP]    = values[BACK];
  values[BACK]   = values[BOTTOM];
  values[BOTTOM] = temp;
}

//按Y轴旋转90度
void Dice::TurnY() {
  int temp  = values[FRONT];
  values[FRONT] = values[RIGHT];
  values[RIGHT] = values[BACK];
  values[BACK]  = values[LEFT];
  values[LEFT]  = temp;
}

//按Z轴旋转90度
void Dice::TurnZ() {
  int temp   = values[LEFT];
  values[LEFT]   = values[TOP];
  values[TOP]    = values[RIGHT];
  values[RIGHT]  = values[BOTTOM];
  values[BOTTOM] = temp;
}
```

```cpp
// diceApp.cpp
// 程序的主函数
#include <iostream.h>
#include "dice.h"
int main(int argc, char* argv[]) {
  Dice aDice;

  for(int i=1;i<10;i++) {
    cout << "第" << i << "次掷得的骰子正面值是：" << aDice.Cast() << endl;
    for( int s = Dice::FRONT;s<=Dice::BACK; ++s) {
      Dice::SIDE side = (Dice::SIDE)s;
      cout << Dice::Names[side] << "面=" << aDice.FaceValue(side) << endl;
    }
  }
  return 0;
}
```
