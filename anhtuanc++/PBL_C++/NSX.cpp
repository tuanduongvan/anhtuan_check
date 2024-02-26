#include "NSX.h"
#include <iomanip>

NSX::NSX()
{
    this->MA_NSX = " ";
    this->Ten_NSX = " ";
}

string NSX::get_MANSX()
{
    return this->MA_NSX;
}

void NSX::NhapNSX()
{
    cout << "Nhap ma_NSX: ";
    cin >> this->MA_NSX;
    cout << "Nhap ten_NSX: ";
    cin >> this->Ten_NSX;

}

istream& operator >> (istream& is, NSX& n)
{
    is >> n.MA_NSX;
    is >> n.Ten_NSX;
    return is;

}

ostream& operator << (ostream& os, const NSX& n)
{
    os << "|" << n.MA_NSX << setw(5) << "|" << setw(11) << n.Ten_NSX << setw(3) << "|" << endl;
    os << "-----------------------" << endl;
    return os;
}

ostream& operator << (const NSX& n, ostream& os)
{
    os << n.MA_NSX << " " << n.Ten_NSX << endl;
    return os;
}