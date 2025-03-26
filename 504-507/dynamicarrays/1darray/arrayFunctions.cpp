#include <iostream>
#include "arrayFunctions.h"

using std::cin, std::cout, std::endl;

void loadRandom(int*& ary, unsigned int size) {
    // let's limit to three digit numbers
    //cout << "starting loadRandom..." << endl;
    if (ary != nullptr) {
      delete [] ary;
      ary = nullptr;
    }
    ary = new int[size];
    
    for (size_t i=0; i<size; ++i) {
        int num = rand()%1000;
        ary[i] = num;
    }
}

void insert(int val, unsigned int index, 
          int ary[], unsigned int& size) {
  // We'll do together
  if (index > size) {
    index = size; // or throw exception
  }
  for (unsigned int i=0; i < size-index; ++i) {
    ary[size-i] = ary[size-i-1];
  }
  ary[index] = val;
  size++;
}

void removeAtIndex(unsigned int index, 
          int ary[], unsigned int& size) {
  if (index >= size) {
    // throw exception
  }
  for (unsigned int i=index; i<size-1; ++i) {
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