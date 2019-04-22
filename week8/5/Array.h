//
// Created by Yesterday17 on 4/22.
//

#ifndef OOPCLASSWORK_ARRAY_H
#define OOPCLASSWORK_ARRAY_H
#include <vector>

namespace WEEK8_5 {
template<class T>
class Array {
 public:
  explicit Array(int sizeA, int sizeB);
  T *&operator[](const int &i);
 private:
  T **value = nullptr;
};

template<class T>
Array<T>::Array(int sizeA, int sizeB) {
  this->value = new T*[sizeA];
  for (int i = 0; i < sizeA; i++) {
    this->value[i] = new T[sizeB];
  }
}

template<class T>
T *&Array<T>::operator[](const int &i) {
  return this->value[i];
}

}

#endif //OOPCLASSWORK_ARRAY_H
