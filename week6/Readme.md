# 面向对象程序设计上机练习（一）

## 1

一个 `C++` 应用程序，由三个 `cpp` 文件和若干头文件组成，`cpp`文件分别为 `MyMain.cpp`，`func1.cpp`，`func2.cpp`。

```cpp
// MyMain.cpp

#include <iostream.h>
int main(int global_argc, char* global_argv[]) {
    cout << g2(10) << endl;
    return 0;
}
```

```cpp
// Func1.cpp

int f1(int num) {
    return g1(num * 2);
}
```

```cpp
// Func2.cpp

int g1(int num) {
    return num * num;
}

int g2(int num) {
    return f1(num * 3);
}
```

1. 请添加必要的头文件，使此程序能编译通过并执行。理解包含警戒的作用。
2. 如果 `main`，`f1`，`g1`，`g2` 或更多的函数之间有更为复杂的调用关系，头文件一般按怎样的规律写呢？
3. 请总结出 `cpp` 文件与`.h` 文件的关系，以及头文件中存放的内容。
4. 若 `main`，`f1`，`g1`，`g2` 函数中都用到常量 `YEARDAYS(365)`，和 `WON(1)`，`TUE(2)`，`WED(3)`，`THU(4)`，`FRI(5)`，`STA(6)`，`SUN(7)`，如何写头文件？

---

## 2

以 `max` 函数为例，实现不同参数传递方式（传值/传引用），不同参数常量性，以及不同的返回值类型（值返回，引用返回，常量引用返回）等情况下, `max` 函数的参数虚实结合和 `max` 的各种使用和它们间的异同。注意参数不同形式时，哪些形式的调用是可以的？哪些算重载函数？哪些是完全等价的？

```cpp
int max(int, int);
int max(const int, const int);
const int max(int, int);
int max(int&, int&);
int& max(int&, int&);
int& max(const int&, const int&);
const int& max(int&, int&);
const int& max(const int&, const int&);
// ...
```

`main` 函数中，可能有如下的调用：

```cpp
int retValue01 = max(1, 2);
int retValue02 = max(a, b);
max(a, 3) = 5;
max(a, b) = max(c, d);
```

等形式。

---

## 3

练习类的定义与多文件实现

类 `A` 的定义在头文件 `a.h` 中，

```cpp
class A {
   public:
    void Display() const {
        cout << "The argment is NULL" << endl;
    }

    void Display(const char* str) const {
        cout << "The argment is " << str << endl;
    }
    void OtherFunc() {
    }
};
```

`main` 函数写在 `mainApp.cpp` 文件中，

```cpp
int main(int global_argc, char* global_argv[]) {
    A aA;

    if (global_argc > 1) {
        aA.Display(global_argv[1]);
    } else {
        aA.Display();
    }

    cout << sizeof(A) << endl;

    return 0;
}
```

1. 查看上述程序的执行结果。理解命令行参数、对象的大小、函数重载。
2. 现将 `Display` 函数分别改成以 `inline` 形式和纯外联实现，试一试。理解内联/外联实现在编程中的注意事项。
3. 试一试在 `a.h` 中，写或不写包含警戒，程序是否正确执行。
4. 给类 `A` 增加一个整型的类变量 `aStaticInt` 和一个类方法，在 `main` 函数中调用该方法。掌握类变量的声明和定义。进一步，试一试，类变量是一个数组呢？
5. 现再增加一个类 `B`，并放入 `b.h` 中。

```cpp
class B {
   public:
    void Func() {
        cout << "This is member function Func()" << endl;
    }

   private:
    A aA;
};
```

并在主函数中调用 `B` 中的成员函数 `Func`.

6. 针对 `(5)`，重新按 `(3)` 中的要求试一试。若将 `Func` 的实现改成外联实现，按 `(3)` 中的要求，再试一试。
   准确理解包含警戒的作用，以及各 cpp 文件独立编译的含义。

7. 将 `(5)` 中的 `B` 改成：

```cpp
class B {
   public:
    B(A& aA) {
        pA = &aA;
    }
    void Func() {
        cout << "This is member function Func()" << endl;
    }
    void NewFunc() {
        pA->OtherFunc();
    }

   private:
    A* pA;
};
```

试一试，让程序编译通过并执行。

8. 将 `B` 中的 `NewFunc` 函数以外联的形式实现，`b.h` 可以怎么写？
   理解 `class A;` 与 `#include "a.h"` 的含义差别，理解外联实现的好处。

---

## 4

练习将实际生活中的事物，抽象成类，并给出类的设计

(找出数据成员和成员函数并用 C++的类表示出来即可)

1. 笔、钢笔
1. 文件、目录
1. 打印机、显示器
1. 太阳、月亮

---

## 5

练习读懂类的代码，练习使用已有的类。

下面的 `TRandom` 类是用线性调和算法，实现的一个伪随机数发生器，仔细阅读代码，理解其含义。
线性调和算法的基本原理是：对于给定的 `N`、`M` 和 `K`，任给一个 `X`，不断用 `X=((N\*X+M) mod K )` 进行迭代计算，那么得到的无穷多个 `x` 值，近似于在 `(0, K)` 上的均匀分布．其中 `N`，`M`，`K` 为较大的数（N 最好是素数）。

```cpp
#include <limits.h>   // 声明INT_MAX和ULONG_MAX常量
#include <windows.h>  // 声明GetTickCount()函数，其返回从开机到现在经过的毫秒数
// #include <stdlib.h>   // 声明rand和srand函数
// #include <time.h>     // 声明time函数
class TRandom {
   public:
    // 缺省使用系统时间(开机后经过的毫秒数)为种子
    TRandom(long seed = 0) {
        mSeed = (seed ? seed : GetTickCount());
    }

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
    int Next() {
        int loops = mSeed % 3;
        for (int i = 0; i <= loops; i++)
            Change();
        return int(mSeed / 2);
    }
    unsigned long mSeed;  // 随机数发生器的种子
};
```

现有一个大小为 54 的整型数组，其元素分别为 `0, 1, 2, ..., 53`.

1.  注意类中的 `public` 和 `private`，理解访问控制的作用．
1.  请利用给出的 `TRandom` 类，完成此数组的”洗牌”过程，并输出洗牌后的顺序。写出相应的完整 `C++` 程序。
    思考：用 `TRandom` 类，洗牌后，54 张牌的排列大约多少种可能?现实中 54 张可有多少种排列方法?
1.  利用给出的 `TRandom`，使用投针法，估算 PI 值。
    投针法：在半径为 1 的 1/4 圆内，随机投针，若落在圆内，则圆内计数加 1；
    这样，若总投掷数为 `N` 次，落在圆内 `M` 次，随着 `N` 的增大，
    `M/N` 约等于 `PI/4`，即 `PI` 约等于 `4\*M/N`.

---

## 6

一个骰子(dice)有 6 个面，各面的点数为 `1-6`，但各面之间的相对位置是固定的。

请实现 Dice 类，其主要完成：

1. 模拟掷骰子过程（Cast），并返回掷得得点数；
2. 报告当前各面的点数。
3. 模拟一次掷两个或多个骰子，并返回得到的总点数。
   实现该类时，取得随机数可使用系统函数 `srand` 和 `rand`，也可使用上例中的 `TRandom` 类。
