#include <iostream>
#include <vector>
#include <string>
#include "patient.h"
using namespace std;

//class Patient;//khai báo forward 
class Doctor 
{
    string nameD;
    vector<Patient *> patient;
    public:
        Doctor(string = "");
        ~Doctor();
        void addPatient(Patient* );
        string getName() const;
        friend ostream& operator << (ostream&,const Doctor&);

};
