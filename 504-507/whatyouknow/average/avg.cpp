#include <iostream>
using std::cin, std::cout, std::endl;

int main() {
    double sum = 0;
    unsigned int count = 0;
    double num = 0;
    do {
        cin >> num;
        if (num >= 0) {
            sum += num; // sum = sum + num;
            count++;
        }
    } while (num >= 0);

    if (count == 0) {
        cout << "No numbers entered." << endl;
    }
    else
        cout << "average: " << sum/count << endl;
}