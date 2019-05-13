//
// Created by Yesterday17 on 5/13.
//

#ifndef OOPCLASSWORK_CAT_H
#define OOPCLASSWORK_CAT_H

#include "../2/Monster.h"
#define extends : public

namespace WEEK11_3 {
class Cat extends WEEK11_2::Monster {
  uint64_t attackDamage(Monster &b) override;
};
}

#endif //OOPCLASSWORK_CAT_H
