#ifndef PIXEL_H
#define PIXEL_H

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
    unsigned short getR() { return r; }
    void setR(unsigned short red);
    unsigned short getG() { return g; }
    void setG(unsigned short green);
    unsigned short getB() { return b; }
    void setB(unsigned short blue);
};


#endif