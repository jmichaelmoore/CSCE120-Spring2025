#include <iostream>
#include "vectorFunctions.h"

using std::cin, std::cout, std::endl, std::vector;

vector<int> loadRandom(size_t size) {
    // let's limit to three digit numbers
    //cout << "starting loadRandom..." << endl;
    vector<int> ret;
    for (size_t i=0; i<size; ++i) {
        int num = rand()%1000;
        ret.push_back(num);
    }
    return ret;
}

vector<int> insert(vector<int> v, int val, size_t index) {
    if (index >= v.size()) {
        throw std::out_of_range("Index is too large");
    }
    //cout << "starting insert..." << endl;
    //cout << "val: " << val << endl;
    //cout << "index: " << index << endl;
    if (index < v.size()) {
        // insert
        v.insert(v.begin()+index, val);
    }
    else {
        v.push_back(val);
    }
    return v;
}

vector<int> removeFirstOf(vector<int> v, int val) { // first instance of
    size_t i = 0;
    while (i < v.size() && v.at(i) != val) {
        ++i; // or i++;
    }
    if (i < v.size()) {
        v.erase(v.begin()+i);
    }
    return v;
}

int getMax(vector<int> v) {
    //cout << "starting getMax..." << endl;
    int maxVal;
    maxVal = v.at(0);
    for (size_t i=1; i<v.size(); ++i) {
        if (v.at(i) > maxVal) {
            maxVal = v.at(i);
        }
    }
    return maxVal;
}

void print(vector<int> v) {
    // print "empty vector" if there is nothing in the vector
    //cout << "starting print..." << endl;
    for (size_t i=0; i<v.size(); ++i) {
        cout << v.at(i) << " ";
    }
    cout << endl;
}