//
// Created by Yesterday17 on 4/29.
//

#include "../menu/Menu.h"
#include "1/B.h"

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
    }
});
