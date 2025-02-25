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
std::vector<int> loadRandom(size_t size);
void insert(std::vector<int>& v, int val, size_t index);
void removeFirstOf(std::vector<int>& v, int val); // first instance of
int getMax(const std::vector<int>&);
void print(const std::vector<int>&);

#endif