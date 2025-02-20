#include <iostream>
#include <vector>

using std::vector, std::cout, std::endl;

int main() {
    vector<int> v = { 1, 4, 7, 18, 44, 13, 11, 21};
    for (size_t i=0; i<v.size(); ++i) {
        int& tmp = v.at(i);
        tmp /= 2;
    }
    for (size_t i=0; i<v.size(); ++i) {
        cout << v.at(i) << endl;
    }

}