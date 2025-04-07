#include "DynamicInt.h"

DynamicInt::DynamicInt(const DynamicInt& src) :
  val(nullptr) {
    val = new int(*(src.val));
}

DynamicInt::~DynamicInt() {
  delete val;
  val = nullptr;
}

DynamicInt& DynamicInt::operator=(const DynamicInt& src) {
  if (this != &src) { // check for self assignment
    //delete old memory
    delete val;
    // allocate new memory & copy value
    val = new int(*(src.val));
  }
  return *this;
  // could have done with one line in this special case
  // *val = *(src.val);
}

DynamicInt& DynamicInt::operator=(int val) { 
  *(this->val) = val; 
  return *this;
}

std::ostream& operator<<(std::ostream& os, const DynamicInt& src) {
  os << src.get();
  return os;
}