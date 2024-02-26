#include "SV.h"

SV::SV(int mlsh,int k, int mhp, int sl, int m)
    :LSH(mlsh, k), HP(mhp, sl)
{
    cout << "SV" << endl;
    this->MSSV = m;
}

SV::~SV()
{
    cout << "huy Sv" << endl;
}

void SV::showSv()
{
    HP::showHP();
    LSH::showLSH();
    cout << "MSSV = " << this->MSSV << endl;
} 

void SV::show()
{
    cout << "show SV" << endl;
}