#include "doctor.h"

Doctor::Doctor(string name)
    :nameD(name)
{}

Doctor::~Doctor()
{}

void Doctor::addPatient(Patient *p)
{
    this->patient.push_back(p);
    p->addDoctor(this);
}

string Doctor::getName() const
{
    return this->nameD;
}

ostream& operator << (ostream& os, const Doctor& d)
{
    int number = d.patient.size();
    if(number == 0)
    {
        os << d.nameD << "has no patient right now" << endl;
    }
    else 
    {
        os << d.nameD << "is setting patient: ";
        for (int i; i < number; i++)
            os << d.patient[i]->getname() << " ";
            os << endl;
    }
    return os;
}