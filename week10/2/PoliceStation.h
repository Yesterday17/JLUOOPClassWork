//
// Created by Yesterday17 on 5/6.
//

#ifndef OOPCLASSWORK_POLICESTATION_H
#define OOPCLASSWORK_POLICESTATION_H

#include <string>
#include <map>
#include "Policeman.h"

namespace WEEK10_2 {
class PoliceStation {
 private:
  std::map<std::string, Policeman *> policemen;
 public:
  void AddPoliceman(std::string name, int money);
  void AddPoliceman(std::string name);
  Policeman *getPoliceman(std::string name);
  void PrintReport();
};
}

#endif //OOPCLASSWORK_POLICESTATION_H
