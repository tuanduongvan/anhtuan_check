#include "patient.h"

void Patient::addDoctor(Doctor* d)
{
    this->doctor.push_back(d);
}

Patient::Patient(string name)
    :nameP(name)
{}

Patient::~Patient()
{}

string Patient::getname() const
{
    return this->nameP;
}

ostream& operator << (ostream& os,const Patient& p )
{
      int number = p.doctor.size();
    if(number == 0)
    {
        os << p.nameP << "has no doctor right now" << endl;
    }
    else 
    {
        os << p.nameP << "is setting doctor: ";
        for (int i; i < number; i++)
        {
            os << p.doctor[i]->getName() << " ";
            os << endl;
        }
    }
    return os;
}