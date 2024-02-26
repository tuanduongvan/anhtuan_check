#include "LoaiVT.h"
#include <iomanip>

LoaiVT::LoaiVT()
{
    this->MA_LoaiVT = " ";
    this->Ten_LoaiVT = " ";
}

string LoaiVT::get_MA_LoaiVT()
{
    return this->MA_LoaiVT;
}

void LoaiVT::Nhap_loaivt()
{
    cout << "nhap ma loai vat tu: ";
    cin >> this->MA_LoaiVT;
    cout << "nhap ten loai vat tu: ";
    cin >> this->Ten_LoaiVT;
}

istream& operator >> (istream& is, LoaiVT& n)
{
    is >> n.MA_LoaiVT;
    is >> n.Ten_LoaiVT;
    return is;

}

ostream& operator << (ostream& os, const LoaiVT& n)
{
    os << "|" << n.MA_LoaiVT << setw(8) << "|" << setw(12) << n.Ten_LoaiVT << setw(3) << "|" << endl;
    os << "---------------------------" << endl;
    return os;
}

ostream& operator << (const LoaiVT& l, ostream& os)
{
    os << l.MA_LoaiVT << " " << l.Ten_LoaiVT << endl;
    return os;
}