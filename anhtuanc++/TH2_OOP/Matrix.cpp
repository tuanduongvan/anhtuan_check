#include "Matrix.h"


Matrix::Matrix(int _row, int _column, int _default) : row(_row), column(_column)
{
    Ar = new int *[this->row];
    for (int i = 0; i < this->row; i++)
    {
        *(Ar + i) = new int[this->column];
        for (int j = 0; j < this->column; j++)
            *(*(Ar + i) + j) = _default;
    }
}

Matrix::~Matrix()
{
    for (int i = 0; i < this->row; i++)
    {
        delete[] * (Ar + i);
    }
    delete[] Ar;
}

int* Matrix::operator [] (int i){
        return Ar[i];
}

Matrix &Matrix::operator + (const Matrix &input)
{
    if (this->row != input.row || this->column != input.column)
        throw string("khong the cong ma tran");
    for (int i = 0; i < this->row; i++)
        for (int j = 0; j < this->column; j++)
            *(*(this->Ar + i) + j) += *(*(input.Ar + i) + j);
    return *this;
}

Matrix &Matrix::operator - (const Matrix &input)
{
    if (this->row != input.row || this->column != input.column)
        throw string("khong the tru ma tra");
    for (int i = 0; i < this->row; i++)
        for (int j = 0; j < this->column; j++)
            *(*(this->Ar + i) + j) -= *(*(input.Ar + i) + j);
    return *this;
}

Matrix Matrix::operator * (Matrix& m) {
    if (this->column != m.row) {
        throw std::invalid_argument("Số cột trong ma trận thứ nhất phải bằng số hàng trong ma trận thứ hai");
    }

    Matrix result(this->row, m.column);
    for (int i = 0; i < this->row; ++i) {
        for (int j = 0; j < m.column; ++j) {
            for (int k = 0; k < this->column; ++k) {
                result[i][j] += this->Ar[i][k] * m[k][j];
            }
        }
    }

    return result;
}

istream &operator >> (istream &inp, Matrix &_m)
{
    for (int i = 0; i < _m.row; i++)
        for (int j = 0; j < _m.column; j++)
        {
            cout << "nhap gia tri index [" << i << "][" << j << "]: ";
            inp >> *(*(_m.Ar + i) + j);
        }
    return inp;
}

ostream &operator<<(ostream &out, const Matrix &_m)
{
    out << "Print matrix: " << endl;
    for (int i = 0; i < _m.row; i++)
    {
        for (int j = 0; j < _m.column; j++)
            out << *(*(_m.Ar + i) + j) << " ";
        out << endl;
    }
    return out;
}