#pragma once
#include <iostream>
#include <math.h>
using namespace std;

class Vector
{
    private:
        int dimension;
        int *Ar;

    public:
        Vector(int);
        ~Vector();
        Vector &operator + (const Vector &);
        Vector &operator - (const Vector &);
        int& operator [] (const int);//da nang hoa toan tu dinh pham vi
        double operator * (const Vector &); //tinh tich vo huong cua hai vector
        double operator ^ (int) const;
};