#include <iostream>

using std::cout, std::endl;

int main(int argc, char *argv[]) { // sometimes you'll see (int argc, char** argv)
  // argc: number of cstrings, argv: array of cstrings
  cout << "executable: " << argv[0] << endl;
  cout << "number of tokens: " << argc << endl;
  // print remaining parameters in reverse order
  for (int i=1; i < argc; ++i) {
    cout << argv[i] << endl;
  }
}