#include <iostream>
#include "arrayFunctions.h"

using std::cin, std::cout, std::endl;

void loadRandom(int ary[], unsigned int size) {
}

void insert(int val, unsigned int index, 
          int ary[], unsigned int& size) {
  // We'll do together
}

void removeAtIndex(unsigned int index, 
          int ary[], unsigned int& size) {

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
