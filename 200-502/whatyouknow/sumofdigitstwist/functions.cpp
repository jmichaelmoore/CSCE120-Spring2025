#include "functions.h"

int sumOfDigits(int val) {
    int sum = 0;
    int rightdigit = 0;
    while (val != 0) {
        int leftdigit = val%10;
        if (leftdigit%2 == 0) {
            sum += rightdigit;
        }
        else {
            sum -= rightdigit;
        }
        //sum += digit; // sum = sum + digit;
        rightdigit = leftdigit;
        val /= 10; // val = val/10;
    }
    sum += rightdigit;
    return sum;
}
