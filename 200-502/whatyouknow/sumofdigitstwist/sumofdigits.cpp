#include <iostream>
#include "functions.h"

using std::cin, std::cout, std::endl;

int main() {
    int val = 0;
    cin >> val;
    cout << "sum is " << sumOfDigits(val) << endl;
}