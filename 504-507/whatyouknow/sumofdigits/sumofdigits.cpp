#include <iostream>
#include "functions.h"

using std::cin, std::cout, std::endl;

int main() {
    int num = 0;
    cin >> num;

    cout << "sum: " << sumOfDigits(num) << endl;
}