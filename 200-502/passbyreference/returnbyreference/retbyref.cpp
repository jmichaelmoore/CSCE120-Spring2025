#include<iostream>
#include <vector>

using std::vector, std::cout, std::endl;

int main() {
    vector<int> v = {1, 5, 6, 9, 11, 15, 16, 14};
    for (size_t i=0; i<v.size(); ++i) {
        int& tmp = v.at(i);
        tmp /= 2;
    }
    for (size_t i=0; i<v.size(); ++i) {
        cout << v.at(i) << endl;
    }
}