#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include<iostream>

//write clase definition and method declarations
class DynamicIntArray {
    int* ary;
    size_t size;
    size_t capacity;
    void increaseCapacity(size_t cap=0);
public:
    DynamicIntArray(): ary(nullptr), size(0), capacity(0) {}
    DynamicIntArray(size_t size, int val=0);
};


#endif