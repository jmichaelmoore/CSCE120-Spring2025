#include <iostream>
#include <cmath>

using std::cin, std::cout, std::endl;

void printEquation(double a, double b, double c) {
    if (a != 0) {
        cout << a << "x^2";
    }
    if (b != 0) {
        if (a != 0) {
            cout << " + ";
        }
        cout << b << "x";
    }
    if (c != 0) {
        if (a != 0 || b != 0) {
            cout << " + ";
        }
        cout << c;
    }
    if (a != 0 || b !=0 || c != 0) {
        cout << " = 0";
    }
    else {
        cout << "0 = 0";
    }
    cout << endl;
}

void solveLinear(double b, double c) {
    if (b == 0) {
        cout << "Invalid equation";
    }
    else {
        double x = -c/b;
        cout << "x = " << x;
    }
    cout << endl;
}

void processReal(double a, double b, double c, double disc) {
    double x1 = (-b - sqrt(disc))/(2*a);
    cout << "x = " << x1 << endl;
    double zero1 = a*x1*x1 + b*x1 + c;
    if (fabs(zero1 - 0) > 0.000001) {
        cout << "invalid x1" << endl;
    }
    if (disc != 0) { // there is a second root
        double x2 = (-b + sqrt(disc))/(2*a);
        double diff = x2 - 0;
        double zero2 = a*x2*x2 + b*x2 + c;
        if (fabs(zero2 - 0) > 0.000001) {
            cout << "invalid x2" << endl;
        }
            cout << "x = " << x2 << endl;
    }
}

void processImaginary(double a, double b, double c, double disc) {
    disc = -1*disc;
    double real = -b/(2*a);
    double img = sqrt(disc);
    cout << real << " + " << img << "i" << endl;
    cout << real << " - " << img << "i" << endl;
}

void solveQuadratic (double a, double b, double c) {
    double disc = b*b - 4*a*c;
    if (disc < 0) {
        processImaginary(a, b, c, disc);
    }
    else {
        processReal(a, b, c, disc);
    }
}

int main() {
    cout << "input coefficients a, b, & c: ";
    double a, b, c;
    cin >> a >> b >> c;
    printEquation(a, b, c);
    if (a == 0) {
        solveLinear(b, c);
    }
    else {
        solveQuadratic(a, b, c);
    }
}