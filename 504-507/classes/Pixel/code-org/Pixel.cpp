// define a class Pixel
// explain public / private
// has integers for red, green, and blue
// constructors
//  - default
//  - all given

#include <iostream>
#include "Pixel.h"

void Pixel::setR(unsigned int r)  {
    if (r > 255) {
        throw std::out_of_range("Red must be between 0 and 255");
    }
    this->r = r;
}

void Pixel::setG(unsigned int g)  {
    if (g > 255) {
        throw std::out_of_range("Green must be between 0 and 255");
    }
    this->g = g;
}

void Pixel::setB(unsigned int b)  {
    if (b > 255) {
        throw std::out_of_range("Blue must be between 0 and 255");
    }
    this->b = b;
}




Pixel::Pixel(unsigned short v) : r(v), g(v), b(v) {
    if (v > 255) {
        throw std::out_of_range("Value must be between 0 and 255");
    }
}
Pixel::Pixel(unsigned short r, unsigned short g, unsigned short b) :
    r(r), g(g), b(b) {
    if (r > 255) {
        throw std::out_of_range("Red must be between 0 and 255");
    }
    if (g > 255) {
        throw std::out_of_range("Green must be between 0 and 255");
    }
    if (b > 255) {
        throw std::out_of_range("Blue must be between 0 and 255");
    }
}


