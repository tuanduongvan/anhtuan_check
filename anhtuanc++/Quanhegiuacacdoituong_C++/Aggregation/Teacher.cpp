#include "Teacher.h"

Teacher::Teacher(string name, int age)
    :name(name), age(age)
{}

Teacher::~Teacher()
{}

ostream& operator << (ostream& os, const Teacher& t)
{
    os << t.name << ", " << t.age << endl;
    return os;
}