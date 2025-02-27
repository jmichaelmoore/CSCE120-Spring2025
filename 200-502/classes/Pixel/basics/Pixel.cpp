#include <iostream>;
// define a class Pixel
// explain public / private
// has integers for red, green, and blue
// constructors
//  - default
//  - all given

class Pixel {
    unsigned short r;
    unsigned short g;
    unsigned short b;
public:
    Pixel() : r(0), g(0), b(0) {}
    Pixel(unsigned short v) : r(v), g(v), b(v) {
        if (v > 255) {
            throw std::out_of_range("value must be between 0 and 255");
        }
    }
    Pixel(unsigned int r, unsigned int g, unsigned int b) 
        : r(r), g(g), b(b) {}
    // getters and setters
    unsigned short getR() { return r; }
    void setR(unsigned short red);
    unsigned short getG() { return g; }
    void Pixel::setG(unsigned short green);
    unsigned short getB() { return b; }
    void Pixel::setB(unsigned short blue);
};

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

int main() {
    Pixel p1;
    Pixel p2(33);
    Pixel p3(5, 6, 7);
}