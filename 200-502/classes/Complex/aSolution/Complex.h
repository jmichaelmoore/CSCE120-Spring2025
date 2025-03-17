#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class Complex {
  double real;
  double imag;

public:
  Complex() : real(0.0), imag(0.0) {}
  Complex(double real, double imag) : real(real), imag(imag) {}
  Complex(double real) : real(real), imag(0.0) {}
  double getReal() const { return real; }
  void setReal(double real) { this->real = real; }
  double getImaginary() const { return imag; }
  void setImaginary(double imag) { this->imag = imag; }
  bool operator==(const Complex& rhs) const;
  Complex operator+(const Complex& rhs) const;
  Complex& operator+=(const Complex& rhs);
  Complex& operator-();
};

std::ostream& operator<<(std::ostream& os, const Complex& rhs);
Complex operator+(double lhs, const Complex& rhs);


#endif