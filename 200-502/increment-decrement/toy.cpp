#include <iostream>
#include <sstream>

using std::cin, std::cout, std::endl, std::string;

int main() {
    // demo pre-decrement and post-decrement
    int a = 3;
    int b = 4;
    int j = 2 * a++;
    int k = 2 * ++b;
    cout << "j: " << j << endl;
    cout << "k: " << k << endl;
}