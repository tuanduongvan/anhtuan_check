#include "myclass.h"

myclass::myclass(string s)
    :sms(s)
{}

myclass::~myclass()
{}

void myclass::A()
{
    cout << "MC - A" << endl;
}
void myclass::B()
{
    cout << "MC -B " << endl;
}