#include <iostream>
#include <vector>
#include <string>

using std::cin, std::cout, std::endl, std::vector;

void printVectorInt(vector<int> v, std::string label) {
    cout << label << ": ";
    for (unsigned int i=0; i<v.size(); ++i) {
        cout << v.at(i) << " ";
    }
    if (v.size() == 0) {
        cout << "Empty vector";
    }
    cout << endl;
}

int main() {
    // a)
    // declare empty vector and add elements
    vector<int> a;
    for (unsigned int i = 0; i<5; ++i) {
        a.push_back(i+1);
    }
    // print
    printVectorInt(a, "a");

    // b)
    // declare/define array with 5 elements
    vector<int> b(3);
    // initialize with loop (traditional)
    for (unsigned int i=0; i<b.size(); ++i) {
        b.at(i) = 8-i;
    }
    // print
    printVectorInt(b, "b");

    // c)
    // initialize all with same value in command
    vector<int> c(4, 12);
    // print
    printVectorInt(c, "c");

    // d)
    // initialize with braces (modern)
    vector<int> d = {2, 13, 22, 4, -55, 9};
    // print
    printVectorInt(d, "d");
}