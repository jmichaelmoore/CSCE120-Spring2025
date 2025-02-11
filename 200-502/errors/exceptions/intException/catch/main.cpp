#include <iostream>

using std::cin, std::cout, std::endl;

void z() {
    cout << "start z" << endl;
    // just for fun (odd number)
    // throw int
    throw 3;
}

void y() {
    cout << "start y" << endl;
    // just for fun (even number)
    // throw int
    throw 8;
} 

int main() {
    cout << "start main" << endl;
    cout << "enter version a or b: ";
    char version = 'c';
    cin >> version;
    try {
        if (version == 'a') {
            y();
        }
        else if (version == 'b') {
            z();
        }
        else throw 'z';
    }
    catch (int i) {
        cout << "caught " << i << endl;
    }
    catch (char c) {
        cout << "caught " << c << endl;
    }
    catch (...) {
        cout << "caught something" << endl;
    }
    cout << "end main" << endl;
}