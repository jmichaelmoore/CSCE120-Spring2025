#include "DynamicIntArray.h"

void DynamicIntArray::increaseCapacity(size_t cap) {
    size_t newCapacity = capacity_*2;
    if (cap > 0 && cap > capacity_) {
        newCapacity = cap;
    }
    if (newCapacity == 0) {
        newCapacity = 1;
    }
    // allocate new array
    int* temp = new int[newCapacity];

    // copy values
    for (size_t i=0; i<capacity_; ++i) {
        temp[i] = ary[i];
    }

    // delete old memory
    delete [] ary;

    // updates
    ary = temp;
    capacity_ = newCapacity;
    temp = nullptr; // not really needed, but good practice
}

DynamicIntArray::DynamicIntArray(size_t size, int val) :
            ary(nullptr), size_(size), capacity_(0) {
    increaseCapacity(size);
    for (size_t i=0; i<size; ++i) {
        ary[i] = val;
    }
}