#include "matrix.h" 

matrix::matrix(int r, int c, int t)
    :row(r), col(c)
{
    this->p = new int* [this->row];
    for (int i = 0; i < this->row; i++)
    {
        *(this->p + i) = new int[this->col];
        for (int j = 0; j < this->col; j++)
        {
            *(*(this->p + i)  + j) = t;
            //this->p[i][j] = t;
        }
    }
}

matrix::~matrix()
{
    for (int i = 0; i < this->row; i++)
    {
        delete[] *(this->p + i);

    }
    delete[] this->p;
}

void matrix::show()
{
     for (int i = 0; i < this->row; i++)
    {
        for (int j = 0; j < this->col; j++)
        {
           cout << (*this)(i, j) << " ";
        }
        cout << endl;
    }
}

ostream& operator << (ostream& os, const matrix& m)
{
    for (int i = 0; i < m.row; i++)
    {
        for (int j = 0; j < m.col; j++)
        {
           os << m.p[i][j] << " ";
        }
        os << endl;
    }
    return os;
}

int& matrix::operator () (const int& i, const int& j)
{
    static int ngu = 0;
    return (i >= 0 && i < this->row && j >= 0 && j < this->col)
    ? *(*(this->p + i) +j ) : ngu;
}