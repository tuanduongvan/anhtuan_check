// #include "patient.h"
#include "doctor.h"

int main()
{
    Patient *p1 = new Patient("BN1");
    Patient *p2 = new Patient("BN2");
    Patient *p3 = new Patient("BN3");
    Doctor *d1 = new Doctor("BS1");
    Doctor *d2 = new Doctor("BS2");
    d1->addPatient(p1);
    d2->addPatient(p1);
    d2->addPatient(p3);
    cout << *d1;
    cout << *d2;
    cout << *p1;
    cout << *p2;
    cout << *p3;
    delete p1; delete p2; delete p3;
    delete d1;
    delete d2;

    return 0;


}