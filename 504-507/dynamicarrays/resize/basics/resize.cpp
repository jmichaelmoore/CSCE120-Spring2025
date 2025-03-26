#include <iostream>

using std::cin, std::cout, std::endl;

int main() {
    // put a dynamic array on the heap and load it with values
    unsigned int capacity = 2;
    unsigned int size = 0;
    int* nums = new int(capacity);
    nums[0] = 7;
    nums[1] = 9;

    // resize
    // create temporary variable and allocate based on new size
    capacity *= 2;
    int* temp = new int(capacity);

    //copy values from original array to the new array
    for (unsigned int i=0; i<size; ++i) {
        temp[i] = nums[i];
    }

    // delete old array
    delete [] nums;

    // update original array variables
    // capacity already updated
    // size was not changed
    // set nums to the location of the new array
    nums = temp;

    // do not delete temp, but you can set temp to nullptr
    temp = nullptr;

    // can now use the new capacity
    nums[2] = 3;
}