#include <iostream>

using std::cout, std::endl, std::cin, std::string;

int main () {
    string name;
    cout << "Hello Aggies!" << endl;
    cout << "What is your name? ";
    cin >> name;
    cout << "Welcome to CSCE 120 " << name << "!" << endl;
    return 0; // optional in main function
}