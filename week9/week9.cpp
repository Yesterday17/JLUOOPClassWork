//
// Created by Yesterday17 on 4/29.
//

#include "../menu/Menu.h"
#include "1/B.h"
#include "2/C.h"
#include "3/YetAnotherWallWithDoor.h"
#include "3/WallWithDoor.h"

Menu *week9 = new Menu(u8"面向对象程序设计上机练习（三）", std::vector<MenuItem>{
    {
        u8"类的继承",
        []() {
          std::cout << "2. 编译错误: data1 为 private" << std::endl;
          std::cout << std::endl << "4. 结果如下:" << std::endl;
          WEEK9_1::B b(1, 2);
          b.f();
          b.g();
          b.f(3);
          b.h();
          std::cout << std::endl << "5. b.g() 非法，因为 g 为 private" << std::endl;

          std::cout << std::endl << "7. a.f(1); 和 a.h(); 无法通过编译" << std::endl;
          WEEK9_1::A a(1);
          WEEK9_1::B b2(2, 3);
          a.f();
          b2.f();
          a.g();
          b2.g();
          // a.f(1);
          b2.f(1);
          // a.h();
          b2.h();

          WEEK9_1::A *p = new WEEK9_1::B(1, 2);

          std::cout << std::endl << "9. (A*)p->f(): " << std::endl;
          p->f();
          std::cout << std::endl << "   p->f(): " << std::endl;
          (new WEEK9_1::B(1, 2))->f();

          std::cout << std::endl << "10. 不能通过编译 " << std::endl;
          // p->f(1);

          std::cout << std::endl << "11. 无法执行 p->h()" << std::endl;
          p->g();
          // p->h();

          std::cout << std::endl << "12. 执行结果如下:" << std::endl;
          delete p;

          std::cout << std::endl << std::endl;
        }
    },
    {
        u8"多继承",
        []() {
          WEEK9_2::C c(1, 2, 3);
          std::cout << "2. main 函数中只能调用MyFuncs()" << std::endl;
          c.MyFuncs();

          std::cout << std::endl << "3,4. 见代码" << std::endl;
        }
    },
    {
        u8"游戏",
        []() {
          int way;
          std::cout << "请选择单继承(0)/多继承(others)实现: ";
          std::cin >> way;

          WEEK9_3::IBaseWallWithDoor *wd;
          if (way == 0) {
            wd = new WEEK9_3::YetAnotherWallWithDoor();
          } else {
            wd = new WEEK9_3::WallWithDoor();
          }

          for (int i = 0; i < 10; i++) {
            int color;

            std::cout << "请输入粉刷的颜色(0:green, 1: red, others): ";
            std::cin >> color;

            wd->PaintWall(color);
          }
        }
    }
});
