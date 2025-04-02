#include "DynamicIntArray.h"

void DynamicIntArray::increaseCapacity(size_t cap) {
    size_t newcapacity = capacity*2;
    if (cap > 0 && cap > capacity) {
        newcapacity = cap;
    }
    if (newcapacity == 0) {
        newcapacity = 1;
    }

    // create new array
    int* temp = new int[newcapacity];

    // copy values
    for (size_t i=0; i<size; ++i) {// could use size
        temp[i] = ary[i];
    }

    // delete old memory
    delete [] ary;

    // updates
    ary = temp;
    capacity = newcapacity;
    temp = nullptr;
}

DynamicIntArray::DynamicIntArray(size_t size, int val) :
                ary(nullptr), size(size), capacity(0) {
    if (size == 0) {
        throw std::invalid_argument("size cannot be 0");
    }
    increaseCapacity(size);
    for (unsigned int i=0; i<this->size; ++i) {
        ary[i] = val;
    }
}