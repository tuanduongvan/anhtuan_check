#pragma once
#include <iostream>
#include <cmath>
using namespace std;

class Polynomial
{
        int degree;
        double* coefficients;

    public:
        Polynomial(int degree);
        ~Polynomial();
        //da nang hoa cac phep toan

        double& operator [] (int);
        double operator () (double x) const;
        Polynomial operator + (const Polynomial& p) const;
        Polynomial operator - (const Polynomial& p) const;
        Polynomial operator * (const Polynomial& p) const;
        Polynomial& operator = (const Polynomial& p);
};
