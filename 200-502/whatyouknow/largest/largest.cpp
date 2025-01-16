#include <iostream>

using std::cout, std::cin, std::endl;

int main() {
    double a, b, c, largest;
    a = b = c = largest = 0;
    cin >> a >> b >> c;
    if (a > b && a > c) {
        largest = a;
    }
    else if (b > c) {
        largest = b;
    }
    else {
        largest = c;
    }
    cout << "largest: " << largest << endl;
}