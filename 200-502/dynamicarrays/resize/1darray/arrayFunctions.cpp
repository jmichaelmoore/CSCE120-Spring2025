#include <iostream>
#include "arrayFunctions.h"

using std::cin, std::cout, std::endl;

void resize(int*& ary, unsigned int& capacity) {
  unsigned int newCapacity = capacity*2;
  if (capacity == 0) {
    newCapacity = 1;
  }
  int* temp = new int[newCapacity];
  // if (temp == nullptr) {
  //   // throw exception
  //   throw std::bad_alloc("Unable to allocate new array");
  // }

  // if capacity is 0, then we'll never get into the loop so will never try to dereference nullptr
  for (unsigned int i=0; i<capacity; ++i) {
    temp[i] = ary[i];
  }

  delete [] ary; // deleting nullptr is not an error

  capacity = newCapacity;
  ary = temp;
  temp = nullptr;
}

void loadRandom(int*& ary, unsigned int size, unsigned int& capacity) {
  // should throw an exception if size > SIZE
  capacity = size;
  ary = new int[size];
  for (unsigned int i=0; i<size; ++i) {
    int val = rand()%1000;
    ary[i] = val;
  }
}

void insert(int val, unsigned int index, 
          int*& ary, unsigned int& size, unsigned int& capacity) {
  // We'll do together
  // check to make sure index is in bounds
  if (index > size) {
    index = size;
  }
  cout << "capacity before: " << capacity << endl;

  // do I have enough space
  if (size == capacity) {
    resize(ary, capacity);
  }

  cout << "capacity after: " << capacity << endl;


// shift value to the right 
  for (unsigned int i = 1; i <= size-index; ++i) {
    ary[size-i + 1] = ary[size-i];
  }
  // add new item to the index
  ary[index] = val;
  size++;

}

void removeAtIndex(unsigned int index, 
          int ary[], unsigned int& size) {
  if (index >= size) {
    return; // or throw an exception
  }
  for (unsigned int i = index; i<size-1; ++i) {
    ary[i] = ary[i+1];
  }
  size--;
}

void removeFirstOf(int val, 
          int ary[], unsigned int& size) {

}

int getMax(const int ary[], unsigned int size) {
  int maxVal = ary[0];
  for (unsigned int i=1; i<size; ++i) {
    if (ary[i] > maxVal) {
      maxVal = ary[i];
    }
  }
  return maxVal;
}

int getMin(const int ary[], unsigned int size) {
  // do on your own
  return 0;
}

unsigned int countVal(int val, const int ary[], unsigned int size) {
  // do on your own
  return 0;
}

// print including empty
void print(const int ary[], unsigned int size) {
  for (unsigned int i=0; i<size; ++i) {
    cout << ary[i] << endl;
  }
}