#include "QL_LoaiVT.h"
#include "fstream"
#include <iomanip>
QL_LoaiVT::QL_LoaiVT()
{
    this->p = NULL;
    this->length1 = 0;
}

QL_LoaiVT::~QL_LoaiVT()
{
    delete[] p;
}

void QL_LoaiVT::Add_LoaiVT(const LoaiVT& n)
{
    if (this->length1 == 0)
    {
        this->p = new LoaiVT[this->length1 + 1];
        *(this->p + this->length1) = n;
    }
    else
    {
        LoaiVT* temp = new LoaiVT[this->length1];
        for (int i = 0; i < this->length1; i++)
        {
            *(temp + i) = *(this->p + i);
        }
        delete[] this->p;
        this->p = new LoaiVT[this->length1 + 1];
        for (int i = 0; i < this->length1; i++)
        {
            *(this->p + i) = *(temp + i);
        }
        *(this->p + this->length1) = n;
        delete[] temp;
    }
    this->length1++;
}

LoaiVT& QL_LoaiVT::operator [] (const int& x)
{
    static LoaiVT ngu;
    return (0 <= x && x < this->length1) ? *(this->p + x) : ngu;
}

int QL_LoaiVT::Vitri(LoaiVT n)
{
    int index = -1;
    for (int i = 0; i < this->length1; i++)
    {
        if (((*this)[i]).get_MA_LoaiVT() == n.get_MA_LoaiVT())
            index = i;
        break;
    }
    return index;
}

void QL_LoaiVT::show_lvt()
{
    cout << "---------------------------" << endl;
    cout << "|MA_LoaiVT" << setw(2) << "|" << setw(12) << "TEN_LoaiVT" << setw(3) << "|" << endl;
    cout << "---------------------------" << endl;
    for (int i = 0; i < this->length1; i++)
    {
        cout << *(this->p + i);

    }

}

void QL_LoaiVT::remove(const LoaiVT& n)
{
    int index = QL_LoaiVT::Vitri(n);//chu y o day
    if (index >= 0)
    {
        for (int i = index; i < this->length1 - 1; i++)
        {
            *(this->p + i) = *(this->p + i + 1);
        }
        this->length1--;
    }
    else
        cout << "NSX khong duoc quan ly" << endl;
}