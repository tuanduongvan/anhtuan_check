#include "Vector.h"
Vector::Vector(int _dimension) : dimension(_dimension)
{
    Ar = new int[this->dimension];
    for (int i = 0; i < this->dimension; i++)
        *(Ar + i) = 0;
}

Vector::~Vector()
{
    delete[] Ar;
}

Vector &Vector::operator + (const Vector &_v)
{
    int max_dimension = (this->dimension >= _v.dimension) ? this->dimension : _v.dimension;
    Vector tmp(max_dimension);
    for (int i = 0; i < max_dimension; i++)
        *(tmp.Ar + i) = *(this->Ar + i) + *(_v.Ar + i);
    delete[] this->Ar;
    this->dimension = max_dimension;
    *this = tmp;
    return *this;
}

Vector &Vector::operator - (const Vector &_v)
{
    int max_dimension = (this->dimension >= _v.dimension) ? this->dimension : _v.dimension;
    Vector tmp(max_dimension);
    for (int i = 0; i < max_dimension; i++)
        *(tmp.Ar + i) = *(this->Ar + i) - *(_v.Ar + i);
    delete[] this->Ar;
    this->dimension = max_dimension;
    *this = tmp;
    return *this;
}

double Vector::operator * (const Vector &v)
{   
    double mul=0;
    for(int i = 0; i < this->dimension; i++){
        mul += *(this->Ar + i) * (*(v.Ar + i));
    }
    return mul;
}

double Vector::operator ^ (int) const
{
 double sum = 0;
    for (int i = 0; i < this->dimension; ++i) {
        sum += Ar[i] * Ar[i];
    }
    return sqrt(sum);
}


int& Vector::operator [] (const int i)
{
    return Ar[i];
}
