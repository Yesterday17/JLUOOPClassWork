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
