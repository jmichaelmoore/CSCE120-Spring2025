#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include<iostream>

//write clase definition and method declarations
class DynamicIntArray {
    int* ary;
    size_t size_;
    size_t capacity_;
    void increaseCapacity(size_t cap=0);
  public:
    DynamicIntArray() : ary(nullptr), size_(0), capacity_(0) {}
    DynamicIntArray(size_t size, int val=0);
    // capacity
    size_t size() const { return size_; }
    size_t capacity() const { return capacity_; }
    bool empty() const { return size_ == 0; }
    // getters / setters
    int at(size_t index) const;
    int operator[](size_t index) const;
    int& at(size_t index);
    int& operator[](size_t index);
    void push_back(int val);
};

#endif