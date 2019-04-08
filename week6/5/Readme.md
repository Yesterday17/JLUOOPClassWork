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
