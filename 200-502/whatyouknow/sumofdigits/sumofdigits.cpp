#include <iostream>

using std::cin, std::cout, std::endl;

int main() {
    int val = 0;
    int sum = 0;
    cin >> val;
    while (val != 0) {
        int digit = val%10;
        sum += digit; // sum = sum + digit;
        val /= 10; // val = val/10;
    }
    cout << "sum is " << sum << endl;
}