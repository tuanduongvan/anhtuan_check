#include "Teacher.h"
#include <vector>

class Department
{
    vector<Teacher*> teacher;
    string nameDep;
    public:
        Department(string = "", Teacher* = nullptr);
        ~Department();
        void addTeacher(Teacher *t);
        friend ostream& operator << (ostream&, const Department&);
};