// define a class Pixel
// explain public / private
// has integers for red, green, and blue
// constructors
//  - default
//  - all given

#include <iostream>
#include "Pixel.h"

Pixel::Pixel(unsigned short v) : r(v), g(v), b(v) {
    if (v > 255) {
        throw std::out_of_range("value must be between 0 and 255");
    }
}

Pixel::Pixel(unsigned int r, unsigned int g, unsigned int b) 
    : r(r), g(g), b(b) {}


void Pixel::setR(unsigned short red) { 
    if (red > 255 ) 
        throw std::out_of_range("red must be between 0 and 255");
    r = red; 
}

void Pixel::setG(unsigned short green) { 
    if (green > 255 ) 
        throw std::out_of_range("green must be between 0 and 255");
    g = green; 
}

void Pixel::setB(unsigned short blue) { 
    if (blue > 255 ) 
        throw std::out_of_range("blue must be between 0 and 255");
    b = blue; 
}

Pixel Pixel::operator+(const Pixel& rhs) const {
    Pixel p;
    p.r = (this->r + rhs.r)/2;
    p.g = (this->g + rhs.g)/2;
    p.b = (this->b + rhs.b)/2;
    return p;
}

/*Pixel& Pixel::operator=(const Pixel& rhs) {
    this->r = rhs.r;
    this->g = rhs.g;
    this->b = rhs.b;
    return *this;
}*/

bool Pixel::operator==(const Pixel& rhs) const {
    return (this->r == rhs.r &&
            this->g == rhs.g &&
            this->b == rhs.b);
}

Pixel& Pixel::operator-() {
    this->r = 255 - this->r;
    this->g = 255 - this->g;
    this->b = 255 - this->b;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Pixel& p) {
    os << "{ " << p.getR() << ", " << p.getG() << ", " << p.getB() << " }";
    return os;
}