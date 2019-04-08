//
// Created by t on 4/8.
//

#ifndef OOPCLASSWORK_WEEK6_PRINTER_H
#define OOPCLASSWORK_WEEK6_PRINTER_H
#define extends :
#define implements :

namespace Week6_4 {
class IOuterDevice {
  virtual void Print() = 0;
};

class Printer implements IOuterDevice {
  void Print() override;
};

class Monitor implements IOuterDevice {
  void Print() override;
};
}

#endif //OOPCLASSWORK_WEEK6_PRINTER_H
