#include "complex.h"

Complex::Complex()
{
    this->Realpart = 0;
    this->Imaginarypart = 0;
}

void Complex::set_ComplexNumber(double r, double im)
{
    this->Realpart = r;
    this->Imaginarypart = im;
}

void Complex::set(double r, double im)
{
    this->set_ComplexNumber(r, im);
}
void Complex::Addition(Complex& p)
{
    this->Realpart += p.Realpart;
    this->Imaginarypart += p.Imaginarypart;
}

void Complex::Subtraction(Complex& p)
{
    this->Realpart -= p.Realpart;
    this->Imaginarypart -= p.Imaginarypart;
}

istream& operator >> (istream& is, Complex& p)
{
    cout << "nhap phan thuc: ";
    is >> p.Realpart;
    cout << "nhap phan ao: ";
    is >> p.Imaginarypart;
    return is;
}

ostream& operator << (ostream& os,const Complex& p)
{
    os << p.Realpart << " + " << p.Imaginarypart << "i" << endl;
    return os;
}