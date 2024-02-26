#include "SVCNTT.h"
SVCNTT::SVCNTT(string m, string n, bool g, double d, string lt)
    :SV(m, n, g,d), lt(lt)
{}

SVCNTT::~SVCNTT()
{
    cout << "xoa SVCNTT roi cu" << endl;
}

void SVCNTT::laptrinh()
{
    cout << "cu biet lap trinh - LT = " << this->lt << endl;
}

void SVCNTT::show()
{
    cout << this->MSSV << ", " << this->name << "," << this->gender << ", " << this->dtb << "," << this->lt  << endl;
}

ostream& operator << (ostream& os,const SVCNTT& s)
{
    os << s.MSSV << ", " << s.name << "," << s.gender << " ," << s.dtb << "," << s.lt << endl;
    return os;
}

const SVCNTT& SVCNTT::operator = (const SVCNTT& s)
{
    cout << " = SVCNTT" << endl;
    return *this;
}