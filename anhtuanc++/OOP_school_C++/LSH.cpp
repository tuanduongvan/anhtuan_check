#include "LSH.h"
#include<iostream>
using namespace std;

LSH::LSH(int m, int k)
    :maLSH(m), khoa(k)
{
    cout << "LSH" << endl;
}

LSH::~LSH()
{
    cout << "huy LSH" << endl;
}

void LSH::showLSH()
{
    cout << "maLSH =" << this->maLSH << ", khoa:" << this->khoa << endl;
}

void show()
{
    cout << "show LHP" << endl;
}