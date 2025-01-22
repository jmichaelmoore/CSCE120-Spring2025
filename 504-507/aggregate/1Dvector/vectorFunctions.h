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
std::vector<int> loadRandom(std::vector<int> ary, size_t size);
std::vector<int> insert(std::vector<int> ary, int val, size_t index);
int getMax(std::vector<int>);
void print(std::vector<int>);

#endif