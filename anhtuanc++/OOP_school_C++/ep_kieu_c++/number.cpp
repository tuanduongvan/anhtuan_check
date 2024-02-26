#include"number.h"

number::number(double d)
    :d(d)
{}

number::~number()
{}

number::operator int ()
{
    return int(this->d);
}

number::operator double ()
{
    return this->d;
}