类间关联

## 1

本例使用了四个文件: `main.cpp`, `walker.h`, `thief.h`, `thief.cpp`

```cpp
// walker.h
#ifndef WALKER_H
#define WALKER_H

class Walker {
public:
  Walker(int m):money(m) {}
  int getMoney() const {return money;}
  void zeroMoney() { money =0; }
private:
  int money;
};

#endif // WALKER_H
```

```cpp
// thief.h
#ifndef THIEF_H
#define THIEF_H

class Walker;
class Thief {
public:
  Thief(int m=0):money(m) {}
  void stole(Walker& walker);
  int  getMoney() const { return money;}
  void zeroMoney() { money =0; }
private:
  int money;
};

#endif // THIEF_H
```

```cpp
//thief.cpp
#include "Walker.h"
#include "Thief.h"

void Thief::stole(Walker& walker) {
  money += walker.getMoney();
  walker.zeroMoney();
}
```

```cpp
//main.cpp
#include <iostream>
using namespace std;

#include "Thief.h"
#include "Walker.h"

int main() {
  Thief  t1;
  Walker w1(100),w2(500),w3(800);
  cout<<"被偷前:"<<endl;
  cout<<"小偷的钱="<<t1.getMoney()<<endl;
  cout<<"w1的钱 ="<<w1.getMoney()<<endl;
  cout<<"w2的钱 ="<<w2.getMoney()<<endl;
  cout<<"w3的钱 ="<<w3.getMoney()<<endl;

  cout<<endl<<"w1被偷后:"<<endl;
  t1.stole(w1);
  cout<<"w1的钱 ="<<w1.getMoney()<<endl;
  cout<<"小偷的钱="<<t1.getMoney()<<endl<<endl;

  cout<<endl<<"w2被偷后:"<<endl;
  t1.stole(w2);
  cout<<"w2的钱 ="<<w2.getMoney()<<endl;
  cout<<"小偷的钱="<<t1.getMoney()<<endl<<endl;

  cout<<endl<<"w3被偷后:"<<endl;
  t1.stole(w3);
  cout<<"w3的钱 ="<<w3.getMoney()<<endl;
  cout<<"小偷的钱="<<t1.getMoney()<<endl<<endl;

  return 0;
}
```

## 2

### 实现 1

（警察局和警察之间，单向关联,thief 类同上）

```cpp
//police.h
#ifndef POLICE_H
#define POLICE_H

class PoliceStation;
class Thief;

class Police {
public:
  Police(PoliceStation& s);
  void catchThief(Thief& theThief);
  int getPrize() const { return prize;}
private:
  PoliceStation& station;
  int prize;
};

#endif // POLICE_H
```

```cpp
//police.cpp
#include "police.h"
#include "Thief.h"
#include "PoliceStation.h"

Police::Police(PoliceStation& s)
  :station(s),prize(0) {
}

void Police::catchThief(Thief& theThief) {
  prize += 100;
  theThief.zeroMoney();
  station.addHonor(1);
}
```

```cpp
//policestation.h
#ifndef POLICESTATION_H
#define POLICESTATION_H

class PoliceStation {
public:
  PoliceStation(int h):honor(h) {}
  int getHonor() const { return honor;}
  void addHonor(int h) { honor += h;}
private:
  int honor;  //声望
};

#endif // POLICESTATION_H
```

```cpp
//main.cpp
#include <iostream>
using namespace std;

#include "Thief.h"
#include "Walker.h"
#include "PoliceStation.h"
#include "police.h"

int main() {
  //用例可为：警察局S有警察p1,p2,p3,贼有t1,t2,t3,t4, p1抓或t2,t3,p2抓获t4,p3没抓获任何贼。t1的初始金钱为500，
  //t2的初始金钱为800，t3的初始金钱为300，t4的初始金钱为1000，S的初始声望为100，警察的初始奖金为0。
  //输出最终S的声望，每个警察的奖金数。

  PoliceStation s(100);      //警察局S初始声望
  Police p1(s),p2(s),p3(s);  //建立3个警察对象
  Thief t1(500),t2(800),t3(300),t4(1000); //建立4个贼对象

  //p1抓或t2,t3
  p1.catchThief(t2);
  p1.catchThief(t3);

  //p2抓获t4
  p2.catchThief(t4);

  cout<<"警察局的声望为："<<s.getHonor()<<endl;
  cout<<"警察p1的Prize = "<<p1.getPrize()<<endl;
  cout<<"警察p2的Prize = "<<p2.getPrize()<<endl;
  cout<<"警察p3的Prize = "<<p3.getPrize()<<endl;

  cout<<"贼t1的Money = "<<t1.getMoney()<<endl;
  cout<<"贼t2的Money = "<<t2.getMoney()<<endl;
  cout<<"贼t3的Money = "<<t3.getMoney()<<endl;
  cout<<"贼t4的Money = "<<t4.getMoney()<<endl;

  return 0;
}
```

### 实现 2

（警察局和警察之间双向关联,thief 类同上,双向关联可有多种实现，本例只是一种）

```cpp
//policestation2.h

#ifndef POLICESTATION2_H
#define POLICESTATION2_H
#include <iostream>
using namespace std;  //便于演示listPolices()功能

class Police;
class PoliceStation2 {

public:
  PoliceStation2(int h):honor(h) {
  //初始时，警察局无警察
  for(int i=0;i<TOTAL;i++) {
    polices[i] = 0;
  }
  }
  int getHonor() const { return honor;}
  void addHonor(int h) { honor += h;}
  bool addPolice( Police *  plc ){
  for(int i=0;i<TOTAL;i++) {
    if (polices[i] == plc) {
  return true;
    }
    if (polices[i] == 0) {
  polices[i] = plc;
  return true;
    }
  }
  return false; //警察添加到警察局失败
  }

  bool removePolice(Police *  plc) {
  for(int i=0;i<TOTAL;i++) {
    if (polices[i] == plc) {
  polices[i] = 0;
  return true;
    }
  }
  return false;  //警察离开警察局失败
  }

  void listPolices() const {
  for(int i=0;i<TOTAL;i++) {
    if (polices[i] != 0) {
  cout<<"有一个警察"<<endl;
    }
  }
  }

private:
  static const int TOTAL = 30;
  int honor;  //声望
  Police * polices[TOTAL];
};

#endif // POLICESTATION2_H
```

```cpp
//police.h
#ifndef POLICE_H
#define POLICE_H

class PoliceStation2;
class Thief;

class Police {
public:
  Police(PoliceStation2& s);
  void catchThief(Thief& theThief);
  int getPrize() const { return prize;}
private:
  PoliceStation2& station;
  int prize;
};

#endif // POLICE_H
```

```cpp
//policestation2.cpp
#include "police.h"

#include "Thief.h"
#include "PoliceStation2.h"

Police::Police(PoliceStation2& s)
  :station(s),prize(0) {
  s.addPolice(this); //添加到警察局
}

void Police::catchThief(Thief& theThief) {
  prize += 100;
  theThief.zeroMoney();
  station.addHonor(1);
}
```

```cpp
//main.cpp
#include <iostream>
using namespace std;

#include "Thief.h"
#include "PoliceStation2.h"
#include "police.h"

int main() {
  PoliceStation2 s(200);      //警察局S初始声望
  Police p1(s),p2(s),p3(s);   //建立3个警察对象

  Thief t1(500),t2(800),t3(300),t4(1000); //建立4个贼对象

  //p1抓或t2,t3
  p1.catchThief(t2);
  p1.catchThief(t3);

  //p2抓获t4
  p2.catchThief(t4);

  cout<<"警察局的声望为："<<s.getHonor()<<endl;
  cout<<"警察p1的Prize = "<<p1.getPrize()<<endl;
  cout<<"警察p2的Prize = "<<p2.getPrize()<<endl;
  cout<<"警察p3的Prize = "<<p3.getPrize()<<endl;

  cout<<"贼t1的Money = "<<t1.getMoney()<<endl;
  cout<<"贼t2的Money = "<<t2.getMoney()<<endl;
  cout<<"贼t3的Money = "<<t3.getMoney()<<endl;
  cout<<"贼t4的Money = "<<t4.getMoney()<<endl;

  s.listPolices();

  return 0;
}
```

## 3

（略）1+2 就够了。

## 4

### 1. 用简单双向关联实现

(顺便体会一下，以外链方式实现.h 的好处。不信的话，可以试一试内联实现是否可行)

```cpp
//man.h
#ifndef MAN_H
#define MAN_H

class Woman;

class Man {
  friend class Woman;  //这里使用友元的目的，是为了不使用Public的void setWife(Woman * w);
public:
  Man(char * str);
  ~Man();
  Woman * getWife() const {return wife;}
  void    marray(Woman * w);
  void    divorce();
  void    display() const;
  //void setWife(Woman * w);
  //由于使用了友元类，该方法不用了。这样也就从全局角度，
  //禁止了其它类(除了友元类woman)写访问wife成员。
private:
  Woman * wife;
  char  * name;
};
#endif // MAN_H
```

```cpp
//man.cpp
#include <iostream>
using namespace std;
#include <string.h>
#include "man.h"
#include "woman.h"


Man::Man(char * str) {
  name = new char[strlen(str)+1];
  strcpy(name,str);
  wife = 0;
}
Man::~Man() {
  delete[] name;
}

void    Man::marray(Woman * w) {
  if (w!=0 && wife ==0 && w->hasband==0) {
  wife = w;
  wife->hasband = this;
  }
}
void Man::divorce() {
  if( wife != 0) {
  wife->hasband = 0;
  wife = 0;
  }
}

void  Man::display() const {
  cout<<"名字: "<<name<<endl;
  if (wife) {
  cout<<"妻子: "<<wife->name<<endl<<endl;
  }else {
  cout<<"妻子: 无"<<endl<<endl;
  }
}
```

```cpp
//woman.h
#ifndef WOMAN_H
#define WOMAN_H

class Man;
class Woman {
  friend class Man; //目的同man.h
public:
  Woman(char * str);
  ~Woman();
  Man *   getHasband() const {return hasband;}
  void    marray(Man * m);
  void    divorce();
  void    display() const;
private:
  Man  * hasband;
  char * name;
};

#endif // WOMAN_H
```

```cpp
//woman.cpp
#include <iostream>
using namespace std;
#include <string.h>
#include "woman.h"
#include "man.h"

Woman::Woman(char * str) {
  name = new char[strlen(str)+1];
  strcpy(name,str);
  hasband = 0;
}

Woman::~Woman() {
  delete[] name;
}

void Woman::marray(Man * m) {
  if (m!=0 && hasband ==0 && m->wife == 0) {
  hasband = m;
  hasband->wife = this;
  }
}

void Woman::divorce() {
  if( hasband != 0) {
  hasband->wife = 0;
  hasband = 0;
  }
}

void  Woman::display() const {
  cout<<"名字: "<<name<<endl;
  if (hasband) {
  cout<<"丈夫: "<<hasband->name<<endl<<endl;
  }else {
  cout<<"丈夫: 无"<<endl<<endl;
  }
}
```

```cpp
//main.cpp
#include <iostream>
using namespace std;
#include "man.h"
#include "woman.h"

int main() {
  Man   m1("管仲"),m2("乐毅"),m3("张良"),m4("韩信");
  Woman f1("沉鱼"),f2("落雁"),f3("闭月"),f4("羞花");

  cout<<"4个帅哥：--------------------------"<<endl;
  m1.display();
  m2.display();
  m3.display();
  m4.display();

  cout<<"4个美女:---------------------------"<<endl;
  f1.display();
  f2.display();
  f3.display();
  f4.display();

  m1.marray(&f1);
  m2.marray(&f2);
  m3.marray(&f3);

  cout<<"成婚3对后：-------------------------"<<endl;
  m1.display();
  m2.display();
  m3.display();
  m4.display();

  f1.display();
  f2.display();
  f3.display();
  f4.display();

  m1.divorce();
  f2.divorce();
  f2.divorce();

  cout<<"分手2对后:--------------------------"<<endl;
  m1.display();
  m2.display();
  m3.display();
  m4.display();

  f1.display();
  f2.display();
  f3.display();
  f4.display();

  return 0;
}
```

### 2. 以关联类的方式实现

(关联类，可以说即是一个关联，也是一个类。)
(本例中，只考虑二者婚姻关系中的结婚年份一个属性，
该属性放 Man 或 Woman 中都不合适，而适合放在关联类中。)

(另： 关联的实现，方法不唯一，本例只是一种实现方式)

```cpp
//man.h
#ifndef MAN_H
#define MAN_H

class Couple;
class Woman;
class Man {
  friend class Couple;
public:
  Man(char * str);
  ~Man();
  char  * getName() const { return name;}
  Woman * getWife() const;
  void    display() const;
private:
  char   * name;
  Couple * couple;
};

#endif // MAN_H
```

```cpp
//woman.h
#ifndef WOMAN_H
#define WOMAN_H

class Couple;
class Man;

class Woman {
  friend class Couple;
public:
  Woman(char * str);
  ~Woman();
  char  * getName() const { return name;}
  Man   * getHasband() const;
  void    display() const;
private:
  char   * name;
  Couple * couple;
};

#endif // WOMAN_H
```

```cpp
//couple.h
#ifndef COUPLE_H
#define COUPLE_H

class Man;
class Woman;
class Couples;

class Couple {
  friend class Couples;
private:
  Couple( Man *  h, Woman * w,int y,int m,int d);
  ~Couple();
public:
  Man   * getHasband() const { return hasband; }
  Woman * getWife() const { return wife; }
  int     getYear() const { return year; }
private:
  Man     *   hasband;
  Woman   *   wife;
  int   year;
  int   month;
  int   day;
};

#endif // COUPLE_H
```

```cpp
//couples.h
#ifndef COUPLES_H
#define COUPLES_H

class Couple;
class Man;
class Woman;

class Couples {
public:
  static Couples& getManager() {
  static Couples mgr;
  return mgr;
  }
public:
  Couple *    marry(Man * h,Woman * w,int y = -200,int m = 0,int d=0);
  void  divorce(Couple * couple);
private:
  Couples();
  ~Couples();
  Couples(const Couples&);
private:
  static const int MAXCOUNT = 100;
  Couple * couples[MAXCOUNT];
};

#endif // COUPLES_H
```

```cpp
//man.cpp
#include <iostream>
using namespace std;
#include <string.h>
#include "man.h"
#include "woman.h"
#include "couple.h"

Man::Man(char * str) {
  couple = 0;
  name = new char[strlen(str)+1];
  strcpy(name,str);
}
Man::~Man() {
  delete[] name;
}

Woman * Man::getWife() const {
  if (couple) return couple->getWife();
  return 0;
}

void  Man::display() const {
  cout<<"名字: "<<name<<endl;
  if (couple) {
  cout<<"妻子: "<<couple->getWife()->getName()<<endl;
  cout<<"成婚日期："<<couple->getYear()<<endl<<endl;
  }else {
  cout<<"妻子: 无"<<endl<<endl;
  }
}
```

```cpp
//woman.cpp
#include <iostream>
using namespace std;
#include "man.h"
#include "woman.h"
#include "couple.h"

Woman::Woman(char * str) {
  couple = 0;
  name = new char[strlen(str)+1];
  strcpy(name,str);
}
Woman::~Woman() {
  delete[] name;
}

Man * Woman::getHasband() const {
  if (couple)
  return couple->getHasband();
  return 0;
}
void  Woman::display() const {
  cout<<"名字: "<<name<<endl;
  if (couple) {
  cout<<"丈夫: "<<couple->getHasband()->getName()<<endl;
  cout<<"成婚日期："<<couple->getYear()<<endl<<endl;
  }else {
  cout<<"丈夫: 无"<<endl<<endl;
  }
}
```

```cpp
//couple.cpp
#include "couple.h"
#include "man.h"
#include "woman.h"

//私有的构造函数
Couple::Couple(Man * h,Woman * w,int y,int m,int d) {
  hasband = h;
  wife    = w;
  hasband->couple = this ;
  wife->couple    = this;
  year = y;
  month = m;
  day  = d;
}

Couple::~Couple() {
  hasband->couple = 0;
  wife->couple    = 0;
}
```

```cpp
//couples.cpp
#include "couples.h"
#include "man.h"
#include "woman.h"
#include "couple.h"


Couple *  Couples::marry(Man * h,Woman * w,int y,int m,int d) {
  for(int i=0;i<MAXCOUNT;i++) {
  if (couples[i] == 0 ) {
    couples[i] = new Couple(h,w,y,m,d);
    return couples[i];
  }
  }
  return 0;
}

void Couples::divorce(Couple * couple) {
  for(int i=0;i<MAXCOUNT;i++) {
  if (couples[i] == couple ) {
    delete couple;
    couples[i] = 0;
  }
  }
}


Couples::Couples() {
  for(int i=0;i<MAXCOUNT;i++) {
  couples[i] = 0;
  }
}

Couples::~Couples() {
  for(int i=0;i<MAXCOUNT;i++) {
  delete couples[i];
  }
}
```

```cpp
//main.cpp
#include <iostream>
using namespace std;
#include "man.h"
#include "woman.h"
#include "couple.h"
#include "couples.h"


int main() {
  Man   m1("管仲"),m2("乐毅"),m3("张良"),m4("韩信");
  Woman f1("沉鱼"),f2("落雁"),f3("闭月"),f4("羞花");

  Couples& mgr = Couples::getManager();

  cout<<"4个帅哥：--------------------------"<<endl;
  m1.display();
  m2.display();
  m3.display();
  m4.display();

  cout<<"4个美女:---------------------------"<<endl;
  f1.display();
  f2.display();
  f3.display();
  f4.display();

  Couple * c1 = mgr.marry(&m1,&f1,-199);
  Couple * c2 = mgr.marry(&m2,&f2,-198);
  Couple * c3 = mgr.marry(&m3,&f3,-197);

  cout<<"成婚3对后：-------------------------"<<endl;
  m1.display();
  m2.display();
  m3.display();
  m4.display();

  f1.display();
  f2.display();
  f3.display();
  f4.display();

  cout<<"分手2对后:--------------------------"<<endl;
  mgr.divorce(c1);
  mgr.divorce(c2);

  m1.display();
  m2.display();
  m3.display();
  m4.display();

  f1.display();
  f2.display();
  f3.display();
  f4.display();

  return 0;
}
```

##6
本例实现中，为了理解方便，将类 A 改名为 Share，将类 B 改名为 User

```cpp
//user.h
#ifndef USER_H
#define USER_H

class Share {
public:
  Share(int num):mData(num) {}
  int     getData() const     {return mData;}
  void    setData(int data)   {mData = data;}
private:
  int mData;
};



class User {
public:
  User(int num = 0);
  ~User();
  User(const User& rhs);
  User& operator=(const User& rhs);
  void display(const char * objName) const;
  int  getData() const;
  void setData(int data);
private:
  void addRef();
  void releaseRef();
private:
  Share * objShared;
  int   * refCount;
};

#endif // USER_H
```

```cpp
//user.cpp
#include <iostream>
using namespace std;

#include "user.h"

User::User(int num)
  :objShared(new Share(num)) {
  refCount = new int(1);
}

User::~User() {
  releaseRef();
}


void User::addRef() {
  ++(*refCount);
}

void User::releaseRef() {
  if (--(*refCount) == 0) {
  delete refCount;
  delete objShared;
  }
}

//
User::User( const User& rhs ) {
  objShared = rhs.objShared;
  refCount  = rhs.refCount;
  addRef();
}


User& User::operator=( const User& rhs) {
  if (this != &rhs) {
  releaseRef();

  objShared = rhs.objShared;
  refCount  = rhs.refCount;
  addRef();
  }
  return *this;
}

int User::getData() const {
  return objShared->getData();
}

//按Copy On Write执行
void User::setData(int data) {
  if(*refCount >= 2 ) {
  releaseRef();
  objShared = new Share(data);
  refCount  = new int(1);
  } else {
  objShared->setData(data);
  }
}

void User::display(const char * objName) const {
  cout<<"对象"<<objName<<"的属性为:"<<endl;
  cout<<"RefCount="<<*refCount<<endl;
  cout<<"共享对象的mData值 = "<< objShared->getData()<<endl<<endl;
}
```

```cpp
//main.cpp
#include <iostream>
using namespace std;
#include "user.h"

int main() {
  User a(100);
  a.display("a");

  cout<<"执行拷贝构造:  User b(a); 后-----------------"<<endl;
  User b(a);
  a.display("a");
  b.display("b");

  cout<<"又执行拷贝构造:  User c(b); 后-----------------"<<endl;
  User c(b);
  a.display("a");
  b.display("b");
  c.display("c");

  cout<<"新建对象d和e：  User d(500),e(999); 后-----------------"<<endl;
  User d(500),e(999);
  d.display("d");
  e.display("e");

  cout<<"执行赋值语句：  d = b; 后-----------------"<<endl;
  d = b;
  a.display("a");
  b.display("b");
  c.display("c");
  d.display("d");
  e.display("e");

  cout<<"按Copy On Write执行修改语句：  c.setData(888);, 后-------"<<endl;
  c.setData(888);
  a.display("a");
  b.display("b");
  c.display("c");
  d.display("d");
  e.display("e");

  cout<<"按Copy On Write执行修改语句：  e.setData(250);, 后-------"<<endl;
  e.setData(250);
  a.display("a");
  b.display("b");
  c.display("c");
  d.display("d");
  e.display("e");


  cout<<"-------------Over--------------"<<endl;
  return 0;
}
```

## 6

参考：定义类 A

```cpp
#include <iostream>

using namespace std;
class A {
public:
  static void * operator new(size_t sz)
  {
  ++newCount;
  newBytes += sz;
  return ::operator new(sz);
  }
  static void operator delete(void * p, size_t sz)
  {
  ++deleteCount;
  deleteBytes += sz;
  ::operator delete(p);
  }
  static void * operator new[](size_t sz)
  {
  ++newCount;
  newBytes += sz;
  return ::operator new(sz);
  }
  static void operator delete[](void * p, size_t sz)
  {
  ++deleteCount;
  deleteBytes += sz;
  ::operator delete(p);
  }
public:
  static int newCount;
  static int newBytes;
  static int deleteCount;
  static int deleteBytes;
private:
  int n1;
  int n2;
  int n3;
};

int A::newCount = 0;
int A::newBytes = 0;
int A::deleteCount = 0;
int A::deleteBytes = 0;

int main() {
  A a1,a2;
  A * pa3= new A;
  A * pa4= new A;
  A * ps  = new A[5];
  delete[] ps;
  delete pa3;
  delete pa4;
  cout<<A::newCount<<endl;
  cout<<A::newBytes<<endl;
  cout<<A::deleteCount<<endl;
  cout<<A::deleteBytes<<endl;
  return 0;
}
```

注：上述代码，在 VC6.0 下会有内部差异。
vc6.0 中内部没有实现`::operator new[]`和`::operator delete[]`, 完全用`::operator new`和`::operator delete`替代了。

## 7

1. `+`应满足交换律，所以 `a+100` 和 `100+a` 都应该合法，若以成员函数形式重载 `operator+`，那么 `a+100` 将编译成 `a.operator+(100)`,编译器将尝试将 `100` 转换成 `A` 类对象。而 `100+a` 不可能编译成 `100.operator+(a)`，只会尝试将 `a` 转换成可与 `100` 相加的类型如 `int` 或 `float`。所以 `operator+` 以自由函数形式更合适。
2. `+=`不应满足交换律，而且左操作数必为类型 `A`，所以成员函数形式更合适。
3. `=`原因同上，而且，应禁止类似 `100=a;`这样的写法，所以只能是成员函数形式。
4. `<<` 也是二元运算符，但两个操作数的类型不一样，左操作数是流类型，右操作数才是类型 `A`，所以只能使用自由函数的形式。

   8.分页器

```cpp
#ifndef PAGE_H
#define PAGE_H

//#define MY_DEBUGGING
class Page {
public:
  Page(int theNum, int theTotal);
  Page& setPage(int theNum , int theTotal = 0);
  Page& prev();
  Page& next();
  Page& prevN();
  Page& nextN();
  Page& first();
  Page& last();
  void  showRange() const;
  void  show() const;
protected:
private:
  static const int N = 5;
  int num;
  int total;
  int rangeStart;
  int rangeEnd;
};

#endif // PAGE_H
```

```cpp
//page.cpp
#include <algorithm>
#include <iostream>
#include <iomanip>
using namespace std;
#include "page.h"

Page::Page(int theNum, int theTotal) {
  setPage(theNum, theTotal);
}

Page & Page::setPage(int theNum, int theTotal) {
  num = max(1, theNum);
  if(theTotal>0) total = max(num, theTotal);
  if(total <= N+4) {
  rangeStart = 1;
  rangeEnd = total;
  }
  else {
  rangeStart = ((num - 1) / N) * N + 1;
  rangeEnd = rangeStart + N-1;

  if(rangeEnd > total) {
    rangeEnd = total;
    rangeStart = rangeEnd - N+1;
  }
  }

  return *this;
}

Page & Page::prev() {
  return setPage(num-1);
}

Page & Page::next() {
  return setPage(num+1);
}
Page & Page::prevN() {
  return setPage(num-N);
}
Page & Page::nextN() {
  return setPage(num+N);
}
Page & Page::first() {
  return setPage(1);
}
Page & Page::last() {
  return setPage(total);
}

void Page::showRange() const {
  cout<<"RangeStart="<<rangeStart<<"\tRangeEnd="<<rangeEnd<<endl;
}


void  Page::show() const {
  cout<<"上页";
  if(rangeStart>1) cout<<setw(5)<<1<<setw(5)<<"…";
  for(int i=rangeStart;i<=rangeEnd;++i) {
  if(i==num) cout<<setw(4)<<i<<"+";
  else cout<<setw(5)<<i;
  }
  if(rangeEnd<total)cout<<setw(5)<<"…"<<setw(5)<<total;

  cout<<setw(5)<<"下页";
  cout<<endl;
}
```
