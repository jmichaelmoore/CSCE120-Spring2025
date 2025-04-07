#include "DynamicInt.h"

DynamicInt::DynamicInt(const DynamicInt& src) :
  val(nullptr) {
    val = new int(*(src.val));
}

DynamicInt& DynamicInt::operator=(const DynamicInt& src) {
  if (this != &src) {
    // delete old memory
    delete val;
    // allocate new memory & copy
    val = new int(*(src.val));
  }
  // *val = *(src.val);  // in this special case
  return *this;
}

DynamicInt& DynamicInt::operator=(int val) { 
  *(this->val) = val; 
  return *this;
}

std::ostream& operator<<(std::ostream& os, const DynamicInt& src) {
  os << src.get();
  return os;
}

DynamicInt::~DynamicInt() {
  delete val;
  val = nullptr;
}

