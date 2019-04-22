//
// Created by Yesterday17 on 4/22.
//

#include "MyString.h"
#include <cstring>
#include <malloc.h>

namespace WEEK8_1 {
MyString::MyString(const char *pData) {
  this->mpData = new char[strlen(pData) + 1];
  strcpy(this->mpData, pData);
}
MyString::MyString(const MyString &str) {
  this->mpData = new char[strlen(str.mpData) + 1];
  strcpy(this->mpData, str.mpData);
}
MyString::~MyString() {
  delete this->mpData;
}
MyString &MyString::operator=(const MyString &str) noexcept {
  if (this != &str) {
    delete this->mpData;
    this->mpData = new char[strlen(str.mpData) + 1];
    strcpy(this->mpData, str.mpData);
  }
  return *this;
}
MyString &MyString::operator+=(const MyString &str) {
  this->mpData = (char *) realloc(this->mpData, (strlen(this->mpData) + strlen(str.mpData) + 1) * sizeof(char));
  strcat(this->mpData, str.mpData);
  return *this;
}
MyString::operator char *() const {
  return this->mpData;
}
}
