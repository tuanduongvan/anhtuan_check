#include <iostream>
using namespace std;

class Complex
{
    double Realpart;
    double Imaginarypart;
    void set_ComplexNumber(double, double);
    public:
        Complex();
        void set(double, double);
        void Addition(Complex&);
        void Subtraction(Complex&);
        friend istream& operator >> (istream&, Complex&);
        friend ostream& operator << (ostream&, const Complex&);
};