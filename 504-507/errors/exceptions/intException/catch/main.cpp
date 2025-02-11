#include <iostream>

using std::cin, std::cout, std::endl;

void z() {
    cout << "start z" << endl;
    // just for fun (odd number)
    // throw int
    throw 7;
}

void y() {
    cout << "start y" << endl;
    // just for fun (even number)
    // throw int
    throw 2;
} 

int main() {
    cout << "start main" << endl;
    cout << "enter version a or b: ";
    char version = 'c';
    cin >> version;
    try {
        if (version == 'a') {
            y();
            z();
        }
        else if (version == 'b') {
            z();
            y();
        }
        else {
            throw 'c';
        }
    }
    catch (int i) {
        cout << i << endl;
    }
    catch (char c) {
        cout << c << endl;
    }
    catch (...) {
        cout << "something" << endl;
    }

    cout << "end main" << endl;
}