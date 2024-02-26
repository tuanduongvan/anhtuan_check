#include "QLNSX.h"
#include "fstream"
#include <iomanip>

QLNSX::QLNSX()
{
    this->p = NULL;
    this->length2 = 0;
}

QLNSX::~QLNSX()
{
    delete[] p;
}

void QLNSX::Add_NSX(const NSX& n)
{
    if (this->length2 == 0)
    {
        this->p = new NSX[this->length2 + 1];
        *(this->p + this->length2) = n;
    }
    else
    {
        NSX* temp = new NSX[this->length2];
        for (int i = 0; i < this->length2; i++)
        {
            *(temp + i) = *(this->p + i);
        }
        delete[] this->p;
        this->p = new NSX[this->length2 + 1];
        for (int i = 0; i < this->length2; i++)
        {
            *(this->p + i) = *(temp + i);
        }
        *(this->p + this->length2) = n;
        delete[] temp;
    }
    this->length2++;
}

NSX& QLNSX::operator [] (const int& x)
{
    static NSX ngu;
    return (0 <= x && x < this->length2) ? *(this->p + x) : ngu;
}

int QLNSX::Vitri(NSX n)
{
    int index = -1;
    for (int i = 0; i < this->length2; i++)
    {
        if (((*this)[i]).get_MANSX() == n.get_MANSX())
            index = i;
        break;
    }
    return index;
}

void QLNSX::remove(NSX& n)
{
    int index = QLNSX::Vitri(n);
    if (index >= 0)
    {
        for (int i = index; i < this->length2 - 1; i++)
        {
            *(this->p + i) = *(this->p + i + 1);
        }
        this->length2--;
    }
    else
        cout << "NSX khong duoc quan ly" << endl;
}

void QLNSX::show_nsx()
{
    cout << "-----------------------" << endl;
    cout << "|MA_NSX" << setw(2) << "|" << setw(11) << "TEN_NSX" << setw(3) << "|" << endl;
    cout << "-----------------------" << endl;
    for (int i = 0; i < this->length2; i++)
    {
        cout << *(this->p + i);
      
    }
}