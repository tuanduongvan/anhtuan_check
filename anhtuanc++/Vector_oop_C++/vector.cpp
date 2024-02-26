// #include  "vector.h"

// Vector::Vector(int size, int t)
//     :size(size)
// {
//     this->p = new int[this->size];
//     for (int i = 1; i < this->size; i++)
//     {
//         *(this->p + i) = t;
//         // this->p[i] = t;
//         //*((*this).p + i) = t;
//         //(*this).p[i] = t;
//     }

// }

// Vector::~Vector()
// {
//     delete[]  this->p;
// }
// void Vector::Show()
// {
//     for(int i = 0; i < this->size; i++)
//     {
//         cout << (*this)[i] << " ";
//     }
//     cout << endl;
// }

// ostream& operator << (ostream& os, const Vector& v)
// {
//     for(int i = 0; i < v.size; i++)
//     {
//         os << v.p[i] << " ";
//     }
//     os << endl;
//     return os;
// }

// int& Vector::operator [] (const int& index)
// {
//     static int ngu = 0;
//     return (index >= 0 && index < this->size) ? *(this->p +index) : ngu;
// }

// Vector::Vector(const Vector& v)
//     :size(v.size)
// {
//     this->p = new int[this->size];
//     for(int i = 0; i < this->size; i ++ )
//     {
//         (*this)[i] = *(v.p + i);
//     }
// }

// const Vector& Vector::operator = (const Vector& v)
// {
//     if(this != &v)
//     {
//         if(this->p != NULL)
//             this->p = NULL;
//         this->size = v.size;
//         this->p = new int[this->size];
//         for (int i = 0; i < this->size; i++)
//         {
//             (*this)[i] = *(v.p + i);
//         }
//     }
//     return *this;

// }


#include "Vector.h"
template<typename T, int U>
Vector<T, U>::Vector()
    : size(U)
{
    this->p = new T[this->size];
    for ( int i = 0; i < this->size; i ++)
    {
        cout << "p[" << i << "]=" ;
        cin >> *(this->p + i);
    }
}

template<typename T, int U >
Vector<T, U>::~Vector()
{
    delete[] this->p;
}

template<typename T, int U>
void Vector<T, U>::Show()
{
    for ( int i = 0; i < this->size; i++)
    {
        cout << *(this->p + i)<< " ";

    }
}

template<typename T, int U>
T& Vector<T, U>::operator [] (const int& index)
{
    T  ngu;
    return (0 < index && index < this->size) ? *(this->p + index) : ngu;
}
template<typename K, int U>
ostream& operator << ( ostream& os, const Vector<K, U>& t)
{
    for (int i = 0; i < t.size; i++)
    {
        os << *(t.p + i) << " ";
    }
    return os;
}
