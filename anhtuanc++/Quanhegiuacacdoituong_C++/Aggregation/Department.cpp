#include "Department.h"

Department::Department(string nameDep, Teacher* teacher)
    :nameDep(nameDep)
{}

Department::~Department()
{
    this->teacher.clear();
}

void Department::addTeacher(Teacher* t)
{
    this->teacher.push_back(t);
}

ostream& operator << (ostream& os, const Department& d)
{
    os << d.nameDep << ":" << endl;
    for (unsigned int i = 0; i < d.teacher.size(); i++)
    {
        os << *d.teacher[i];
    }
    os << endl;
    
    return os;
}
