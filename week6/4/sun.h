//
// Created by t on 4/8.
//

#ifndef OOPCLASSWORK_WEEK6_SUN_H
#define OOPCLASSWORK_WEEK6_SUN_H

#define extends :
#define implements :

#include <stdint.h>
class BaseCelestialBody {
  uint64_t radius;
  uint64_t weight;
};

class Moon extends BaseCelestialBody {
  BaseCelestialBody parentPlanet;
};

class Sun extends BaseCelestialBody {
  uint64_t temperature;
};

#endif //OOPCLASSWORK_WEEK6_SUN_H
