#include <iostream>
#include "arrayFunctions.h"

using std::cin, std::cout, std::endl;

void loadRandom(int*& ary, unsigned int size) {
  // should throw an exception if size > SIZE
  if (ary != nullptr) {
    delete [] ary;
    ary = nullptr;
  }
  ary = new int[size];
  for (unsigned int i=0; i<size; ++i) {
    int val = rand()%1000;
    ary[i] = val;
  }
}

void insert(int val, unsigned int index, 
          int*& ary, unsigned int& size) {
  // We'll do together
  // check to make sure index is in bounds
  if (index > size) {
    index = size;
  }

  for (unsigned int i = 0; i <= size-index; ++i) {
    ary[size-i] = ary[size-i-1]; // item on right = item on left
  }
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