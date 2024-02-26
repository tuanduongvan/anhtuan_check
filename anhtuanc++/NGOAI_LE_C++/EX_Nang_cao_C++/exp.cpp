#include "EXP.h"

EXP::EXP(string s)
    :err(s)
{}

EXP::~EXP()
{}

ostream& operator << (ostream& os, const EXP& p)
{
    os << p.err;
    return os;
}