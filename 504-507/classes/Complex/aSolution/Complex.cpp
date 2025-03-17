#include "Complex.h"

bool Complex::operator==(const Complex& rhs) const {
  return this->real == rhs.real &&
         this->imag == rhs.imag;
}

Complex Complex:: operator+(const Complex& rhs) const {
  Complex ret(this->real+rhs.real, 
              this->imag+rhs.imag);
  return ret;
}

Complex operator+(double lhs, const Complex& rhs) {
  Complex ret(lhs+rhs.getReal(), rhs.getImaginary());
  return ret;
}

Complex& Complex::operator+=(const Complex& rhs) {
  this->real += rhs.real;
  this->imag += rhs.imag;
  return *this;
}

Complex& Complex::operator-() {
  this->real = -1*this->real;
  this->imag  = -1*this->imag;
  return *this;
}

std::ostream& operator<<(std::ostream& os, const Complex& rhs) {
  os << rhs.getReal();
  if (rhs.getImaginary() < 0) {
    os << " - " << (rhs.getImaginary() * -1);
  }
  else {
    os << " + " << rhs.getImaginary();
  }
  return os;
}

