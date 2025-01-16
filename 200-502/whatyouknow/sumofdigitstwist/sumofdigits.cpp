#include <iostream>

using std::cin, std::cout, std::endl;

int main() {
    int val = 0;
    int sum = 0;
    int rightdigit = 0;
    cin >> val;
    while (val != 0) {
        int leftdigit = val%10;
        if (leftdigit%2 == 0) {
            sum += rightdigit;
        }
        else {
            sum -= rightdigit;
        }
        //sum += digit; // sum = sum + digit;
        rightdigit = leftdigit;
        val /= 10; // val = val/10;
    }
    sum += rightdigit;
    cout << "sum is " << sum << endl;
}