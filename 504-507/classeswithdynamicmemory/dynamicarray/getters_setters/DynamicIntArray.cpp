#include "DynamicIntArray.h"

void DynamicIntArray::increaseCapacity(size_t cap) {
    size_t newcapacity = capacity_*2;
    if (cap > 0 && cap > capacity_) {
        newcapacity = cap;
    }
    if (newcapacity == 0) {
        newcapacity = 1;
    }

    // create new array
    int* temp = new int[newcapacity];

    // copy values
    for (size_t i=0; i<capacity_; ++i) {// could use size
        temp[i] = ary[i];
    }

    // delete old memory
    delete [] ary;

    // updates
    ary = temp;
    capacity_ = newcapacity;
    temp = nullptr;
}

DynamicIntArray::DynamicIntArray(size_t size, int val) :
                ary(nullptr), size_(size), capacity_(0) {
    if (size == 0) {
        throw std::invalid_argument("size cannot be 0");
    }
    increaseCapacity(size);
    for (unsigned int i=0; i<this->size_; ++i) {
        ary[i] = val;
    }
}

int DynamicIntArray::at(size_t index) const {
    if (index >= size_) {
        throw std::out_of_range("index >= size");
    }
    return ary[index];
}

int DynamicIntArray::operator[](size_t index) const {
    return ary[index];
}

int& DynamicIntArray::at(size_t index) {
    if (index >= size_) {
        throw std::out_of_range("index >= size");
    }
    return ary[index];
}

int& DynamicIntArray::operator[](size_t index) {
    return ary[index];
}

void DynamicIntArray::push_back(int val) {
    if (size_ == capacity_) {
        increaseCapacity();
    }
    ary[size_] = val;
    size_++;
}
