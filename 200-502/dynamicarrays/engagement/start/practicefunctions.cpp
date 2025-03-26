#include "practicefunctions.h"

void makeary(char*& ary, unsigned int size) {
  if (ary != nullptr) {
    delete [] ary;
    ary = nullptr;
  }
  ary = new char[size];
}

unsigned int sumary(const char* ary, unsigned int size) {
  unsigned int sum = 0;
  for (unsigned int i=0; i<size; ++i) {
    sum += ary[i];
  }
  return sum;
}

void deleteary(char*& ary, unsigned int& size) {
  // deletes all memory on the heap 
  //  and set ary and size to values representing an empty array
  delete [] ary;
  ary = nullptr;
}