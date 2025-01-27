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
    Person p, b;

    // assign values to elements of the struct (access as well)
    p.firstName = "Michael";
    p.lastName = "Moore";
    p.grade = 83.4;

    // individually to each element then to all elements at one time
    //    assing one struct to another struct
    b = p;

    // access elements of the struct - i.e. print them
    cout << p.firstName << " " << p.lastName << ": " << p.grade << endl;
}