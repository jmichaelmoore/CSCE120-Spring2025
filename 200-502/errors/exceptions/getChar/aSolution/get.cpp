#include <iostream>

using std::cin, std::cout, std::endl, std::string;

// deal with specific exception
// parent exception
// any exception

int main() {
    string word = "supercalifragilisticexpialidocious"; // constructor initialzies to empty string, we'll see this soon
    size_t index = 0;
    do {
        cout << "Enter index to show letter or 9999 to exit: ";
        cin >> index;
        if (index != 9999) {
            try {
                cout << word.at(index) << " is the letter at index " << index << endl;
            }
            catch (std::out_of_range& e) {
                cout << "Your index must be less than " << word.size() << endl;
            }
        }
    } while (index != 9999);
}