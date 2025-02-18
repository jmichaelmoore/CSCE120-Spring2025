#include <iostream>
#include <limits>

using std::cout, std::endl, std::cin;

int main() {
  int val;
  do {
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    cout << "Enter an integer: ";
    cin >> val;
  } while (cin.fail());

  cout << "You entered: " << val << endl;
}
