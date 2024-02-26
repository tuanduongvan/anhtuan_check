#include <iostream>
#include "Matrix.h"
#include "Vector.h"
#include "Polynomial.h"
using namespace std;

int main() {
    Polynomial p1(2);
    p1[0] = 2;
    p1[1] = 1;
    p1[2] = 2;
    cout << "Value at x = 4: " << p1(4) << endl;

    Polynomial p2(3);
    p2[0] = -3;
    p2[1] = 3;

    Polynomial p3 = p1 + p2;
    cout << "Value at x = 4: " << p3(4) << endl;

    Vector v(3);
    v[0] = 2;
    v[1] = 3;
    v[2] = 1;
    cout << "Length of vector: " << (v^2) << endl;

    Matrix m(2, 2);
    m[0][0] = 2;
    m[0][1] = 4;
    m[1][0] = 6;
    m[1][1] = 8;
    cout << "Element at (1, 1): " << m[1][1] << endl;

    Matrix m2(2, 2);
    m2[0][0] = 1;
    m2[0][1] = 3;
    m2[1][0] = 5;
    m2[1][1] = 7;

    Matrix m3 = m * m2;

    cout << "Result of multiplication: " << endl;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            cout << m3[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}