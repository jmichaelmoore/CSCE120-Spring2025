#ifndef PIXEL_H
#define PIXEL_H

class Pixel {
    unsigned short r;
    unsigned short g;
    unsigned short b;
public:
    Pixel() : r(0), g(0), b(0) {}
    Pixel(unsigned short v);
    Pixel(unsigned short r, unsigned short g, unsigned short b);
    void setR(unsigned int r);
    unsigned int getR() { return r; }
    void setG(unsigned int g);
    unsigned int getG() { return g; }
    void setB(unsigned int b);
    unsigned int getB() { return b; }

    Pixel operator+(const Pixel& rhs);
    //Pixel& operator=(const Pixel& rhs);
    bool operator==(const Pixel&rhs);
    Pixel& operator-();
};

#endif