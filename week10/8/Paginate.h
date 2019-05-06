//
// Created by Yesterday17 on 5/6.
//

#ifndef OOPCLASSWORK_PAGINATE_H
#define OOPCLASSWORK_PAGINATE_H

namespace WEEK10_8 {
class Paginate {
 private:
  int now;
  int total;
 public:
  Paginate(int n, int tot) : total(tot), now(n) {}
  Paginate setPage(int n, int tot);
  Paginate next();
  Paginate prev();
  Paginate nextN();
  Paginate prevN();
  void show();
};
}

#endif //OOPCLASSWORK_PAGINATE_H
