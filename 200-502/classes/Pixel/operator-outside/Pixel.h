#ifndef PIXEL_H
#define PIXEL_H
#include <iostream>

class Pixel {
    unsigned short r;
    unsigned short g;
    unsigned short b;
public:
    // constructors
    Pixel() : r(0), g(0), b(0) {}
    Pixel(unsigned short v);
    Pixel(unsigned int r, unsigned int g, unsigned int b); 

    // getters and setters
    unsigned short getR() const { return r; }
    void setR(unsigned short red);
    unsigned short getG() const { return g; }
    void setG(unsigned short green);
    unsigned short getB() const { return b; }
    void setB(unsigned short blue);

    // operators
    Pixel operator+(const Pixel& rhs) const;
    //Pixel& operator=(const Pixel& rhs);
    bool operator==(const Pixel& rhs) const;
    Pixel& operator-();
};

std::ostream& operator<<(std::ostream& os, const Pixel& p);
#endif