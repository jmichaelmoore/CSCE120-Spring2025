#include <iostream>
#include "vectorFunctions.h"

using std::cin, std::cout, std::endl, std::vector;

vector<int> loadRandom(vector<int> v, size_t size) {
    // let's limit to three digit numbers
    //cout << "starting loadRandom..." << endl;
    vector<int> ret;
    for (size_t i=0; i<size; ++i) {
        int num = rand()%1000;
        v\ret.push_back(num);
    }
    return ret;
}

vector<int> insert(vector<int> v, int val, size_t index) {
    //cout << "starting insert..." << endl;
    //cout << "val: " << val << endl;
    //cout << "index: " << index << endl;

}

vector<int> remove(vector<int> v, int val) { // first instance of

}

int getMax(vector<int> v) {
    //cout << "starting getMax..." << endl;
}

void print(vector<int> v) {
    // print "empty vector" if there is nothing in the vector
    //cout << "starting print..." << endl;
}