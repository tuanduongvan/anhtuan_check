#include "SV.h"

SV::SV(string m, string n, bool g, double d)
    :MSSV(m), name(n), gender(g), dtb(d)
{}

SV::~SV()
{
    cout << "xoa SV roi cu" << endl;
}

ostream& operator << (ostream& os, SV& s)
{
    os << s.MSSV << ", " << s.name << "," << s.gender << " ," << s.dtb << endl;
    return os;
}
 void SV::show()
 {
    cout << this->MSSV << ", " << this->name << "," << this->gender << ", " << this->dtb << endl;
 }

const SV& SV::operator = (const SV& s)
{
    if (this != &s)
    {
        cout << "SV =" << endl;
        this->MSSV = s.MSSV;
        this->name = s.name;
        this->gender = s.gender;
        this->dtb = s.dtb;
    }
    return *this;
}