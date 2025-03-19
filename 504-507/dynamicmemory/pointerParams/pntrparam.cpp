#include <iostream>

using std::cin, std::cout, std::endl;

void redecorate(int* x, int newVal) {
    *x = newVal;
}

void needToMove(int* x) { 
    // actual parameter for x should be assigned a new memory address
    x = new int(*x);
}

int main() {
    int* a = new int(5);
    int* b = a;

    cout << "value of a:  " << a << endl;
    cout << "value of *a: " << *a << endl;
    cout << "value of b:  " << b << endl;
    cout << "value of *b: " << *b << endl;
    cout << endl;

    redecorate(a, 9);
    redecorate(b, 8);

    cout << "value of a:  " << a << endl;
    cout << "value of *a: " << *a << endl;
    cout << "value of b:  " << b << endl;
    cout << "value of *b: " << *b << endl;
    cout << endl;

    needToMove(b);
    redecorate(b, 3);

    cout << "value of a:  " << a << endl;
    cout << "value of *a: " << *a << endl;
    cout << "value of b:  " << b << endl;
    cout << "value of *b: " << *b << endl;
    cout << endl;

    delete a;

}