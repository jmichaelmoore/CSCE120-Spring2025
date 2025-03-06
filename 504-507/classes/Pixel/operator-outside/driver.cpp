#include <iostream>
#include "Pixel.h"

using std::cin, std::cout, std::endl;

int main() {
    Pixel p;
    p.setR(10);
    p.setG(12);
    p.setB(13);
    cout << "{ " << p.getR() << ", " << p.getG() << ", " << p.getB() << " }" << endl;
    Pixel pr(255, 0, 0);
    Pixel pb(0, 0, 255);
    Pixel purple = pr + pb;
    cout << "{ " << purple.getR() << ", " << purple.getG() << ", " << purple.getB() << " }" << endl;
    //p = purple;
    //cout << "{ " << p.getR() << ", " << p.getG() << ", " << p.getB() << " }" << endl;
    cout << (p == purple) << endl;
    p = pr + pb;
    cout << (p == purple) << endl;
    -p;
    cout << "{ " << p.getR() << ", " << p.getG() << ", " << p.getB() << " }" << endl;
    cout << purple << endl;
    cout << pr << endl;
}