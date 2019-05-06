//
// Created by Yesterday17 on 5/6.
//

#include <iostream>
#include "PoliceStation.h"
void WEEK10_2::PoliceStation::AddPoliceman(std::string name, int money) {
  if (this->policemen.find(name) == this->policemen.end()) {
    this->policemen.insert(std::make_pair(name, new Policeman(money)));
  }
}

void WEEK10_2::PoliceStation::AddPoliceman(std::string name) {
  this->AddPoliceman(name, 0);
}

void WEEK10_2::PoliceStation::PrintReport() {
  int prestige = 0;
  for (auto police : this->policemen) {
    std::cout << police.first << ": " << std::endl << "Money: ";
    police.second->printMoney();
    std::cout << std::endl << "Reward: ";
    police.second->printReward();
    std::cout << std::endl << std::endl;
    prestige += police.second->getReward();
  }

  std::cout << "Prestige: " << prestige << std::endl;
}
WEEK10_2::Policeman *WEEK10_2::PoliceStation::getPoliceman(std::string name) {
  return this->policemen.find(name)->second;
}
