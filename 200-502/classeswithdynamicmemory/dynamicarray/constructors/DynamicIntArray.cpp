#include "DynamicIntArray.h"

void DynamicIntArray::increaseCapacity(size_t cap) {
    size_t newCapacity = capacity*2;
    if (cap > 0 && cap > capacity) {
        newCapacity = cap;
    }
    if (newCapacity == 0) {
        newCapacity = 1;
    }
    // allocate new array
    int* temp = new int[newCapacity];

    // copy values
    for (size_t i=0; i<capacity; ++i) {
        temp[i] = ary[i];
    }

    // delete old memory
    delete [] ary;

    // updates
    ary = temp;
    capacity = newCapacity;
    temp = nullptr; // not really needed, but good practice
}