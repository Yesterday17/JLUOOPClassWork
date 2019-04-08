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
