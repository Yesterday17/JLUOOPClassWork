//
// Created by Yesterday17 on 5/6.
//

#include "../1/Walker.h"
#include "../1/Thief.h"
#include "../2/Policeman.h"
#include "../2/PoliceStation.h"

namespace WEEK10_3 {
int main() {
  WEEK10_2::PoliceStation station;
  station.AddPoliceman("p1");
  station.AddPoliceman("p2");

  WEEK10_1::Thief t1, t2;

  WEEK10_1::Walker w1(114514), w2(1919), w3(810);
  t1.steal(w1);
  t2.steal(w2);
  t2.steal(w3);

  station.getPoliceman("p1")->catchThief(t1);
  station.getPoliceman("p2")->catchThief(t2);
  station.PrintReport();
  return 0;
}
}

