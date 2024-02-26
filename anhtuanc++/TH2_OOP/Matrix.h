#pragma once
#include <iostream>
#include <string>
using namespace std;
class Matrix
{
private:
    int row, column;
    int **Ar;

public:
    Matrix(int, int, int = 0);
    ~Matrix();
    Matrix &operator + (const Matrix &);
    Matrix &operator - (const Matrix &);
    int* operator [] (int);
    Matrix operator*(Matrix&);
    //khai bao ham ban
    friend istream &operator>>(istream &, Matrix &);
    friend ostream &operator<<(ostream &, const Matrix &);
};