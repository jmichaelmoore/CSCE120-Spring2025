#include <iostream>

using std::cout, std::endl;

int mi(int j) {
  int i = 5;
  j = j % i;
  return j;
}

int re(int& s, int p) {
  s = 12;
  p = p / 2;
  int z = s*p;
  return mi(z);
}

int doe(int w) {
  int k = 2;
  w += 3;
  cout << "k(" << k << ") ";
  int z = re(k, w);
  cout << "k(" << k << ") ";
  return z + w;
}

int main() {
  int a = 11;
  int b = doe(a);
  cout << "b(" << b << ")" << endl;
  return 0;
}
