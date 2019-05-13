//
// Created by Yesterday17 on 5/13.
//

#ifndef OOPCLASSWORK_CALLBACKOBJECT_H
#define OOPCLASSWORK_CALLBACKOBJECT_H

namespace WEEK11_5 {
class CallBackObject {
 public:
  virtual ~CallBackObject() = default;
  virtual int CallBackFunc(int val) = 0;  // ----(4)-----;
};
}

#endif //OOPCLASSWORK_CALLBACKOBJECT_H
