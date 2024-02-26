#include "HP.h"
#include <iostream>
using namespace std;

HP::HP(int m, int sl)
    :maHP(m), sl(sl)
{
    cout << "HP" << endl;
}

HP::~HP()
{
    cout << " huy HP" << endl;
}

void HP::showHP()
{
    cout << "maHP = " << this->maHP << ", SL = " << this->sl << endl;
}
void HP::show()
{
    cout << " show HP" << endl;
}