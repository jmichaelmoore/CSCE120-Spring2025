#include <iostream>

using std::cin, std::cout, std::endl;

int fib(int n) {
    return 0;
}

int main() {
    int n = 0;
    while (n >= 0) {
        cout << "enter: ";
        cin >> n;
        cout << "ans: " << fib(n) << endl;
    }
}