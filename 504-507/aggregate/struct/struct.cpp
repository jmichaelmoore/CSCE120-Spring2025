#include <iostream>

using std::cin, std::cout, std::endl, std::string;

// define a struct Person
// include firstname, lastname, grade
struct Person {
    string firstName = "";
    string lastName = "";
    double grade = 0;
};

int main() {
    // declare / define a struct variable
    Person p;

    // assign values to elements of the struct (access as well)
    p.firstName = "Michael";
    p.lastName = "Moore";
    p.grade = 84.26;

    // individually to each element then to all elements at one time
    //    assing one struct to another struct
    Person b;
    b = p;

    Person c = { "Miss", "Reveille", 99.75};

    // access elements of the struct - i.e. print them
    cout << c.firstName << " " << c.lastName << ": " << c.grade << endl;
}