#include "Department.h"

int main()
{
    // Teacher *t = new Teacher("NVA", 40);
    // {
    //    Department d("CNTT", t);
    //     cout << d;
    // }

    // cout << *t;
    // delete t;
//buoi 2 (1-n)

    Teacher *t1 = new Teacher("A");
    Teacher *t2 = new Teacher("B");
    Teacher *t3 = new Teacher("C");
    {
        Department dept("CNTT");
        dept.addTeacher(t1);
        dept.addTeacher(t2);
        dept.addTeacher(t3);
    }
    cout << *t1 << *t2 << *t3;
    delete t1;
    delete t2;
    delete t3;
    
    return 0;
}