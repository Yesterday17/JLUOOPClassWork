## 2

```cpp
#include <iostream>

using namespace std;

class A
{
public:
     A(int num):data(num) {}
     void AFuncs() {cout<<"This is A \'s public function!"<<endl;}
protected:
     int data;
};
class B
{
public:
     B(int num):value(num) {}
     void BFuncs() {cout<<"This is B \'s public function!"<<endl;}
protected:
     int value;
};

class C:public A,private B
{
public:
    C(int num1,int num2,int y):A(num1),B(num2),yyy(y) { }
    void MyFuncs()
    {
        BFuncs();
        cout<<"This function call B::BFuncs() !"<<endl;
    }
private:
     int yyy;
};

class NewC:public A
{
public:
    NewC(int num1,int num2,int y)
        :A(num1),pB(new B(num2)),yyy(y)
    { }

    ~NewC()
    { delete pB; }

    NewC(const NewC& obj)
        :A(obj)
    {
        pB = new B(*obj.pB);
        yyy = obj.yyy;
    }

    NewC& operator=(const NewC & rhs)
    {
        if (this != &rhs ) {
            A::operator=(rhs);

            delete pB;
            pB = new B(*rhs.pB);
            yyy = rhs.yyy;
        }
    }

    void MyFuncs()
    {
        pB->BFuncs();
        cout<<"This function call B::BFuncs() !"<<endl;
    }

private:
    B  *  pB;
    int   yyy;
};

int main()
{
    C  obj(1,2,3);
    //C类中公有的只有AFuncs、MyFuncs、构造、析构、拷贝、赋值。
    obj.AFuncs();
    obj.MyFuncs();

    cout << endl << "改写C类为NewC类后..." << endl;
    //NewC类中公有的还是只有AFuncs、MyFuncs、构造、析构、拷贝、赋值。
    NewC newObj(4,5,6);
    newObj.AFuncs();
    newObj.MyFuncs();

    cout << "---------Over-------------" << endl;
    return 0;
}
```

## 3

```cpp
enum class WallColor {COLOR_RED =10,COLOR_GREEN=20};

class WallWithDoor:public Wall,private Door
{
public:
      WallWithDoor(){}
      void Paint(int newColor) {
             if (newColor == (int)WallColor::COLOR_RED)
                 Close();
             else if (newColor == (int)WallColor::COLOR_GREEN)
                 Open( );
             else
                 Wall::Paint(newColor);
      }
};

int main()
{
    WallWithDoor wd;

    wd.Paint((int)WallColor::COLOR_RED);
    wd.Paint((int)WallColor::COLOR_GREEN);
    wd.Paint(0);
}
```

### 3.1

（这里 door 成员更应使用指针或引用形式，便于应用虚机制）

```cpp
enum class WallColor {COLOR_RED =10,COLOR_GREEN=20};
class WallWithDoor:public Wall
{
public:
      WallWithDoor(){}
      void Paint(int newColor) {
             if (newColor == (int)WallColor::COLOR_RED)
                 door.Close();
             else if (newColor == (int)WallColor::COLOR_GREEN)
                 door.Open( );
             else
                 Wall::Paint(newColor);
      }
private:
    Door door;
};

int main()
{
    WallWithDoor wd;

    wd.Paint((int)WallColor::COLOR_RED);
    wd.Paint((int)WallColor::COLOR_GREEN);
    wd.Paint(0);
}
```

### 3.2

（这里 wall/door 成员更应使用指针或引用形式，便于应用虚机制）

```cpp
class WallWithDoor
{
public:
      WallWithDoor(){}
      void Paint(int newColor) {
             if (newColor == (int)WallColor::COLOR_RED)
                 door.Close();
             else if (newColor == (int)WallColor::COLOR_GREEN)
                 door.Open( );
             else
                 wall.Paint(newColor);
      }
      int GetColor() const {return wall.GetColor();}
private:
    Wall wall;
    Door door;

};
int main()
{
    WallWithDoor wd;

    wd.Paint((int)WallColor::COLOR_RED);
    wd.Paint((int)WallColor::COLOR_GREEN);
    wd.Paint(0);
}
```
