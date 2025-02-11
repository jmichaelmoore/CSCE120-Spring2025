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
    if (a == 0 && b == 0 && c == 0) {
        cout << "0 = 0";
    }
    else {
        cout << " = 0";
    }
    cout << endl;
}

void solveLinear(double b, double c) {
    double x = -c/b;
    cout << "x = " << x << endl;
}

void processImaginary(double a, double b, double disc) {
    disc = disc * -1; // make positive
    double real = -b/(2*a);
    double img1 = sqrt(disc)/(2*a);
    cout << "x = " << real << " + " << img1 << "i" << endl;
    cout << "x = " << real << " - " << img1 << "i" << endl;
}

void processReal(double a, double b, double c, double disc) {
    double x1 = (-b + sqrt(disc))/(2*a);
    cout << "x = " << x1 << endl;
    double zero1 = a*x1*x1 + b*x1 + c;
    if (fabs(zero1 - 0) > 0.0000001) {
        cout << "x1 did not check" << endl;
    }
    if (disc != 0) {
        double x2 = (-b - sqrt(disc))/(2*a);
        cout << "x = " << x2 << endl;
        double zero2 = a*x2*x2 + b*x2 + c;
        if (fabs(zero2 - 0) > 0.0000001) {
            cout << "x2 did not check" << endl;
        }
        }
}

void solveQuadratic(double a, double b, double c) {
    double disc = b*b - 4*a*c;
    if (disc < 0) {
        processImaginary(a, b, disc);
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
        if (b == 0) {
            cout << "Can't Solve" << endl;
        }
        else {
            solveLinear(b, c);
        }
    }
    else {
        solveQuadratic(a, b, c);
    }
}