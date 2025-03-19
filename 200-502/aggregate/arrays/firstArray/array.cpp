#include <iostream>

using std::cin, std::cout, std::endl;

const int SIZE = 10;

// function to initialize
void initializeAry(int ary[], int size) {
    for (int i = 0; i<size; ++i) {
        ary[i] = i + 1;
    }
}
// function to print (use const to prevent changing)
void printAry(const int ary[SIZE], int size) {
    for (int i=0; i<size; ++i) {
        cout << ary[i] << " ";
    }
    cout << endl;
}

int main() {
    // declare/define array[]
    int ary[SIZE];
    int size = 5;
    // initialize with braces (modern) - do second
    // initialize with function and loop (traditional) - do first (includes traversal)
    initializeAry(ary, size);
    // print values from array through function (includes traversal)
    printAry(ary, size);
    cout << endl;
}