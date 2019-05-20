## 2

```cpp
class Monster {
public:
  Monster(int hp,int dam,int def) : hitpoint(hp),damage(dam),defense(def) {
  }

  virtual ~Monster( ) {
  }

  bool Fight(Monster & other) {
    while(1) {
      if (Attack(other)) return true;
      if (other.Attack(*this)) return false;
    }
  }

  int GetHitpoint() const { return hitpoint;}
  int GetDamage() const   { return damage;  }
  int GetDefense() const  { return defense; }
  void ReduceHP(int harm) {
    if (harm > 0) {
          hitpoint = hitpoint>harm ? hitpoint-harm : 0;
    }
  }
private:
  virtual bool Attack(Monster& other )=0;
private:
  int hitpoint;
  int damage;
  int defense;
};

class Cat:public Monster {
public:
  Cat(int hp,int dam,int def) : Monster(hp,dam,def){}
private:
  virtual bool Attack(Monster& other) {
    ///猫的攻击力值 * 2 — 对方的防御力值）
    int harm = GetDamage()*2 - other.GetDefense();
    if (harm<1) harm = 1;
    other.ReduceHP(harm);
    return (other.GetHitpoint()<=0);
  }
};

class Dog:public Monster {
public:
  Dog(int hp,int dam,int def) : Monster(hp,dam,def) {}
private:
  virtual bool Attack(Monster& other) {
    ///(狗的攻击力值 — 对方的防御力值 ＋5 )*2  若上式小于2，则取2
    int harm = (GetDamage() - other.GetDefense()+5)*2;
    if (harm<2) harm = 2;
    other.ReduceHP(harm);
    return (other.GetHitpoint()<=0);
  }
};

int main( ) {
  Cat cat(36,10,10);
  Dog dog(36,12,8);
  //Cat cat(37,10,10);
  //Dog dog(37,12,8);

  if (cat.Fight(dog))
    cout<<"Cat is WINNER."<<endl;
  else
    cout<<"Dog is WINNER."<<endl;
  cout<<"Current Each Hitpoints are: "<<endl;
  cout<<"Cat's Hitpoint ="<<cat.GetHitpoint()<<endl;
  cout<<"Dog's Hitpoint ="<<dog.GetHitpoint()<<endl;

  return 0;
}
```

## 3

```cpp
#include <iostream>
using namespace std;

class Fruit {
public:
  Fruit(int w): origin(w), weight(w) {}
  virtual ~Fruit() {}
  virtual int  reduceWater() = 0;
  int  getOrigin() const { return origin;}
  int  getWeight() const { return weight;}
  void setWeight(int w)  { weight = w; }
private:
  const int   origin; ///original weight
  int         weight; ///current weight
};

class Apple: public Fruit {
public:
  Apple(int w): Fruit(w) {}
  virtual int reduceWater() {
    /// an apple reduce 4 each day
    int minWeight = getOrigin() * 3 / 5;
    int oldWeight = getWeight();
    int newWeight = (oldWeight - 4 < minWeight ? minWeight : oldWeight - 4);
    setWeight(newWeight);
    return oldWeight - newWeight;
  }
};


class Orange: public Fruit {
public:
  Orange(int w): Fruit(w) {}
  virtual int reduceWater() {
    /// an orange reduce 3 each day
    int minWeight = getOrigin() * 3 / 5;
    int oldWeight = getWeight();
    int newWeight = (oldWeight - 3 < minWeight ? minWeight : oldWeight - 3);
    setWeight(newWeight);
    return oldWeight - newWeight;
  }
};


class Box {
public:
  Box();
  void addFruit(Fruit & one);
  int  passOneDay();   // return the total reduced weigth
  int  appleCount() const;
  int  orangeCount() const;
  int  totalWeight() const;
public:
  void show( int day);
private:
  Fruit * fruits[8];
};

Box::Box() {
  for(int i = 0; i < 8; ++i)
    fruits[i] = nullptr;
}

void Box::addFruit(Fruit & one) {
  for(int i = 0; i < 8; ++i) {
    if(fruits[i] != nullptr) { continue; }
    fruits[i] = &one;
    return;
  }
}

int  Box::appleCount() const {
  int result = 0;
  for(int i = 0; i < 8; ++i) {
    Apple *p = dynamic_cast<Apple *> (fruits[i]);
    if( p ) ++result;
  }
  return result;
}

int  Box::orangeCount() const {
  int result = 0;
  for(int i = 0; i < 8; ++i) {
      Orange *p = dynamic_cast<Orange *> (fruits[i]);
      if( p ) ++result;
  }
  return result;
}
int  Box::totalWeight() const {
  int total = 0;
  for(int i = 0; i < 8; ++i) {
      if (fruits[i])
          total += fruits[i]->getWeight();
  }
  return total;
}

int  Box::passOneDay() {
    int total = 0;
    for(int i = 0; i < 8; ++i) {
        if (fruits[i])
            total += fruits[i]->reduceWater();
    }
    return total;
}

void Box::show( int day) {
    cout<<"Day = "<<day<<endl;
    cout<<"Apple  Count  = "<<appleCount()<<endl;
    cout<<"Orange Count  = "<<orangeCount()<<endl;
    cout<<"Weigth Before Reduce="<<totalWeight()<<endl;
    cout<<"Total  Reduce = "<<passOneDay()<<endl;
    cout<<"Weigth After Reduce="<<totalWeight()<<endl<<endl;
}

int main() {
    ///create 4 apples
    Apple   apples[]  = { Apple(50), Apple(50), Apple(50), Apple(50) };
    ///create 3 oranges
    Orange  oranges[] = { Orange(30), Orange(30), Orange(30) };

    ///Create a Box
    Box    box;

    /// the 1st day
    box.addFruit(apples[0]);
    box.addFruit(oranges[0]);
    box.show(1);

    /// the 2nd day
    box.addFruit(apples[1]);
    box.addFruit(oranges[1]);
    box.show(2);

    /// the 3rd day
    box.addFruit(apples[2]);
    box.addFruit(oranges[2]);
    box.show(3);

    /// the 4th day
    box.show(4);

    /// the 5th day
    box.show(5);

    /// the 6th day
    box.show(6);

    /// the 7th day
    box.show(7);

    return 0;
}
```

## 4

### (一)

1. `data = new int[len]`
2. `delete[] data`
3. `sum += obj.CallBackFunc(data[i])`
4. `virtual int CallBackFunc(int val) = 0`
5. `srv.Total(*this)`

### (二)

1. `return val*val;`
2. `cout<<”平方和=”<<srv.Total(*this)<<endl;`

### (三)

```cpp
virtual int CallBackFunc(int val){
cout<<val<<”  ”;
return val*val;
}

void RequestB(Server& srv) {
int n = srv.Total(*this);
    cout<<”的立方和=”<<n<<endl;
}

```
