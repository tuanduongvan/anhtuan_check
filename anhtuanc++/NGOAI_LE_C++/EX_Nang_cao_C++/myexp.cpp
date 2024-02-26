#include "myexp.h"

myexp::myexp(string s, int x)
    :EXP(s),s(x)
{}

myexp::~myexp()
{}

ostream& operator << (ostream& os, const myexp& p)
{
    os << p.s << "," << p.err << endl;
}


