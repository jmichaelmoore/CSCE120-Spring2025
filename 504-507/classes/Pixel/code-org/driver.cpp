#include <iostream>
#include "Pixel.h"

using std::cin, std::cout, std::endl;

int main() {
    Pixel p;
    p.setR(10);
    p.setG(12);
    p.setB(13);
    cout << "{ " << p.getR() << ", " << p.getG() << ", " << p.getB() << " }" << endl;
}