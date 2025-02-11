#include <iostream>
#include "vectorFunctions.h"

using std::cin, std::cout, std::endl, std::vector;

vector<int> loadRandom(size_t size) {
    // let's limit to three digit numbers
    //cout << "starting loadRandom..." << endl;
    vector<int> v;
    for (unsigned int i=0; i<size; ++i) {
        int val = rand()%1000;
        v.push_back(val);
    }
    return v;
}

vector<int> insert(vector<int> v, int val, size_t index) {
    if (index >= v.size()) {
        throw std::out_of_range("Your index is too big!");
    }
    //cout << "starting insert..." << endl;
    //cout << "val: " << val << endl;
    //cout << "index: " << index << endl;
    if (index >= v.size()) {
        v.push_back(val);
    }
    else {
        v.insert(v.begin()+index, val);
    }
    return v;
}

vector<int> removeFirstOf(vector<int> v, int val) { // first instance of
    size_t i = 0;
    while (i < v.size() && v.at(i) != val) {
        ++i; // or i++;
    }
    // exit because we didn't find
    // or found and i is the index
    if (i < v.size()) {
        // remove the value
        v.erase(v.begin()+i);
    }
    return v;
}

int getMax(vector<int> v) {
    //cout << "starting getMax..." << endl;
    int maxVal;
    maxVal = v.at(0);
    for (size_t i = 1; i<v.size(); ++i) {
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