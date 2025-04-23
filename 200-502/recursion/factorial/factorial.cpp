#include <iostream>

using std::cin, std::cout, std::endl;

int factorial(int n) {
    if (n==0)
        return 1;
    return n*factorial(n-1);
}

int main() {
    int n = 0;
    while (n >= 0) {
        cout << "enter: ";
        cin >> n;
        cout << "ans: " << factorial(n) << endl;
    }
}