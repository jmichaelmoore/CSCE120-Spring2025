#include <iostream>
#include <vector>
#include "imagefunctions.h"

using std::cout, std::cin, std::endl, std::vector, std::string;

void printMenu(); // function declaration

int main() {
 
  char menuChoice = ' '; // selected menu option
  do {
    printMenu();
    cin >> menuChoice;
    switch (toupper(menuChoice)) { // use toupper so user can input upper or lower case choices
      case 'G':
      case 'S':
      case 'R':
        processImage(menuChoice); // use fall through
        break;
      case 'Q': // does nothing but needed or default will execute
        break;
      default:
        cout << endl << "'" << menuChoice << "' is not a valid option'" << endl << endl;
    }
  } while (toupper(menuChoice) != 'Q'); // use toupper so user can input upper or lower case choices
}

/*  Function printMenu
 *  Return value: none
 */
// You should not modify this function. //
void printMenu() // function definition that is also a declaration
{
  cout << "----------------------------------" << endl;
  cout << " 'G': Make grayscale image" << endl;
  cout << " 'S': Make sepia image" << endl;
  cout << " 'R': Make reverse grayscale image" << endl;
  cout << " 'Q': Quit" << endl;
  cout << "----------------------------------" << endl;
  cout << endl
       << "Please enter your choice: ";
}