#include <iostream>

using std::cin, std::cout, std::endl;

const int SIZE = 7;

// function to initialize
void initializeAry(int ary[SIZE], int size) {
    for (int i=0; i<size; ++i) {
        ary[i] = i + 1;
    }
}
// function to print (use const to prevent changing)
void printAry(const int ary[], int size) {
    for (int i=0; i<size; ++i) {
        cout << ary[i] << " ";
    }
    cout << endl;
}

int main() {
    // declare/define array
    int size = 5;
    int ary[SIZE];
    // initialize with braces (modern) - do second
    // initialize with function and loop (traditinal) - do first (includes traversal)
    initializeAry(ary, size);
    // print values from array through function (includes traversal)
    printAry(ary, size);
    cout << endl;
    //cout << "bad access: " << endl;
    //cout << ary[4918473247] << endl;
}