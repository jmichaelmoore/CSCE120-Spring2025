#include <iostream>
#include <ctime>
#include "vectorFunctions.h" 
// only include header file, NOT the cpp file

using std::cin, std::cout, std::endl, std::vector;

// this is a declaration
void printMenu();

// It would be good to break main into more functions...
//   However, we'll need to learn more about pass by reference
//     before we can do that.
int main() {
  srand(time(NULL));
  
  vector<int> v;  // create empty vector
  
  char menuChoice = ' ';
  
  while ('Q' != toupper(menuChoice)) {
  
    printMenu();
    
    cout << endl << "Please enter choice: ";
    cin >> menuChoice;

    int num = 0;
    size_t index = 0;
    size_t size = 0;
      
    switch (toupper(menuChoice)) {
      case 'L':
        cout << "Input number of random values to load: ";
        cin >> size;
        v = loadRandom(v, size);
        break;
      case 'I':
        cout << "Input value to insert: ";
        cin >> num;
        cout << "Input index to insert: ";
        cin >> index;
          v = insert(v, num, index);
        break;
      case 'R':
        cout << "Input index to delete: ";
        cin >> index;
        /*v = removeAtIndex(v, index);*/
        break;
      case 'F':
        cout << "Input value to delete: ";
        cin >> num;
        /*v = removeFirstOf(v, num);*/
        break;
      case 'X':
        cout << "Max: " << getMax(v);
        cout << endl;
        break;
      case 'N':
        //cout << "Min: " << getMin(v);
        cout << endl;
        break;
      case 'C':
        cout << "Input value to count: ";
        cin >> num;
        //cout << num << " appears " << countVal(v, num);
        cout << " times" << endl;
        break;
      case 'P':
        print(v);
        break;
      case 'S':
        cout << "Size: " << v.size() << endl;
        break;
      default:
        cout << "Invalid option" << endl;
    }
  }
  
  cout << endl << "Goodbye!" << endl;
  
}

// this is a definition
void printMenu() {
  cout << "'L' - Load random values" << endl;
  cout << "'I' - Insert number at index" << endl;
  cout << "'R' - Remove number at index" << endl;
  cout << "'F' - Remove first instance of value" << endl;
  cout << "'X' - Get maximum value" << endl;
  cout << "'N' - Get miniumum value" << endl;
  cout << "'C' - Count instances of number" << endl;
  cout << "'P' - Print values" << endl;
  cout << "'S' - Size" << endl;
  cout << "'Q' - Quit" << endl;
}