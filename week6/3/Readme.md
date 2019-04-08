
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
