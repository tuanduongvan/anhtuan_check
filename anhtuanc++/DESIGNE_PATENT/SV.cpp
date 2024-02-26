#include "SV.h"

SV::SV(int m, bool g, double d)
    :mssv(m), gender(g), dtb(d)
{}
SV::~SV()
{}
ostream& operator << (ostream& os,const SV& s)
{
    os << "ttsv: " << s.mssv << "," << s.gender <<"," << s.dtb << endl;
    return os;
}

int SV::_mssv()
{
    return this->mssv;
}