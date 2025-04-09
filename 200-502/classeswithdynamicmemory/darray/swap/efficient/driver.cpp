#include <iostream>
#include "DynamicArray.h"

using namespace std;

void printArray(string label, const DynamicArray<int>& ary);

int main() {
  // declare/define instance
  DynamicArray<int> a;
  printArray("a", a);

  DynamicArray<int> b(3, 7);
  printArray("b", b);

  DynamicArray<int> c(5, 0);
  printArray("c", c);


  c.at(2) = 2;
  c[0] = 9;

  printArray("c", c);

  b.push_back(1);

  printArray("b", b);

  a.push_back(5);
  printArray("a", a);

  DynamicArray<int> d(b); // copy constructor

  printArray("d",d);

  d.at(0) = 111;
  b.at(b.size()-1) = 222;

  printArray("b", b);
  printArray("d", d);

  a = d; // copy assignment

  printArray("a",a);

  a.at(a.size() -1) = 444;
  d.at(0) = 333;

  printArray("d",d);
  printArray("a", a);

  a.swap(d);

  printArray("d",d);
  printArray("a", a);

}

void printArray(string label, const DynamicArray<int>& ary) {
  cout << label << endl;
  if (ary.empty()) {
    cout << "Empty!" << endl;
  }
  else {
    for (size_t i=0; i<ary.size(); ++i) {
      cout << ary.at(i) << endl;
    }
  }
  cout << endl;
}