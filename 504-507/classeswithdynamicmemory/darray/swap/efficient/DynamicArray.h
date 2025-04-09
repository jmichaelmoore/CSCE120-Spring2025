#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include<iostream>

//write clase definition and method declarations
template <typename T>
class DynamicArray {
    T* ary;
    size_t size_;
    size_t capacity_;
    void increaseCapacity(size_t cap=0);
    void copyAry(const DynamicArray<T>& src);
public:
    DynamicArray<T>(): ary(nullptr), size_(0), capacity_(0) {}
    DynamicArray<T>(size_t size, T val);
    DynamicArray<T>(const DynamicArray<T>&);
    ~DynamicArray<T>();
    DynamicArray<T>& operator=(const DynamicArray<T>&);
    // capacity methods
    size_t size() const { return size_; }
    size_t capacity() const { return capacity_; }
    bool empty() const { return size_ == 0; }
    // getters / setters
    T at(size_t index) const;
    T operator[](size_t index) const;
    T& at(size_t index);
    T& operator[](size_t index);
    void push_back(const T& val);
    void swap(DynamicArray<T>& other);
};

template <typename T>
void DynamicArray<T>::increaseCapacity(size_t cap) {
    size_t newcapacity = capacity_*2;
    if (cap > 0 && cap > capacity_) {
        newcapacity = cap;
    }
    if (newcapacity == 0) {
        newcapacity = 1;
    }

    // create new array
    T* temp = new T[newcapacity];

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

template <typename T>
DynamicArray<T>::DynamicArray(size_t size, T val) :
                ary(nullptr), size_(size), capacity_(0) {
    if (size == 0) {
        throw std::invalid_argument("size cannot be 0");
    }
    increaseCapacity(size);
    for (unsigned int i=0; i<this->size_; ++i) {
        ary[i] = val;
    }
}

template <typename T>
T DynamicArray<T>::at(size_t index) const {
    if (index >= size_) {
        throw std::out_of_range("index >= size");
    }
    return ary[index];
}

template <typename T>
T DynamicArray<T>::operator[](size_t index) const {
    return ary[index];
}

template <typename T>
T& DynamicArray<T>::at(size_t index) {
    if (index >= size_) {
        throw std::out_of_range("index >= size");
    }
    return ary[index];
}

template <typename T>
T& DynamicArray<T>::operator[](size_t index) {
    return ary[index];
}

template <typename T>
void DynamicArray<T>::push_back(const T& val) {
    if (size_ == capacity_) {
        increaseCapacity();
    }
    ary[size_] = val;
    size_++;
}

template <typename T>
void DynamicArray<T>::copyAry(const DynamicArray<T>& src) {
    // copy values
    for (size_t i=0; i < src.size_; ++i) {
        this->ary[i] = src.ary[i];
    }
}

template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& src) :
        ary(new T[src.capacity_]), size_(src.size_), capacity_(src.capacity_){
    copyAry(src);
}

template <typename T>
DynamicArray<T>::~DynamicArray() {
    delete [] ary;
    ary = nullptr;
    capacity_ = 0;
    size_ = 0;
}

template <typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T>& src) {
    if (this != &src) {
        // delete old memory
        delete [] ary;
        // allocate new Memory
        ary = new T[src.capacity_];
        copyAry(src);
        this->capacity_ = src.capacity_;
        this->size_ = src.size_;
    }
    return *this;
}

template <typename T>
void DynamicArray<T>::swap(DynamicArray<T>& other) {
    T* tempAry = this->ary;
    this->ary = other.ary;
    other.ary = tempAry;
    size_t tempS = this->size_;
    this->size_ = other.size_;
    other.size_ = tempS;
    size_t tempC = this->capacity_;
    this->capacity_ = other.capacity_;
    other.capacity_ = tempC;
}

#endif