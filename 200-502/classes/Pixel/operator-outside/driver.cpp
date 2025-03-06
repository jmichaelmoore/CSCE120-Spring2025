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
    Pixel pr(255, 0, 0);
    Pixel pb(0, 0, 255);
    Pixel purple = pr + pb;
    cout << "{ " << purple.getR() << ", " << purple.getG() << ", " << purple.getB() << " }" << endl;
    //p1 = purple;
    cout << "{ " << p1.getR() << ", " << p1.getG() << ", " << p1.getB() << " }" << endl;
    cout << (p1 == purple) << endl;
    p1 = pr + pb;
    cout << (p1 == purple) << endl;
    -p1;
    cout << "{ " << p1.getR() << ", " << p1.getG() << ", " << p1.getB() << " }" << endl;
    cout << p1 << endl;
    cout << pb << endl;
}