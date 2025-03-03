#include <iostream>
#include "Pixel.h"

using std::cin, std::cout, std::endl;

int main() {
    Pixel p1;
    Pixel p2(33);
    Pixel p3(5, 6, 7);
    p1.setR(5);
    p1.setG(6);
    p1.setB(7);
    cout << "{ " << p1.getR() << ", " << p1.getG() << ", " << p1.getB() << " }" << endl;
}