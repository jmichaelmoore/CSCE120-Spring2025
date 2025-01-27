// header guards
#ifndef ARRAYFUNCTIONS_H
#define ARRAYFUNCTIONS_H

#include <vector>

// functions to add
//   loadRandom
//   insert
//   remove at index
//   remove first of
//   getMax // linear search
//   getMin 
//   count val
//   print

// these are declarations
std::vector<int> loadRandom(std::vector<int> v, size_t size);
std::vector<int> insert(std::vector<int> v, int val, size_t index);
std::vector<int> remove(std::vector<int> v, int val); // first instance of
int getMax(std::vector<int>);
void print(std::vector<int>);

#endif