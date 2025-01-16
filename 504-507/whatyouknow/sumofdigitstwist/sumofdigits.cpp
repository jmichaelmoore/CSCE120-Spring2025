#include <iostream>

using std::cin, std::cout, std::endl;

int main() {
    int num = 0;
    int sum = 0;
    int prev = 0;
    cin >> num;
    while (num != 0) {
        int digit = num%10;
        if (digit%2 == 0) {
            sum += prev;
        }
        else {
            sum -= prev;
        }
        prev = digit;
        num /= 10; // num = num / 10;
    }
    sum += prev;
    cout << "sum: " << sum << endl;
}