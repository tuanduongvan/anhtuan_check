#include <iostream>
#include"SVCNTT.h"
using namespace std;
int main()
{
    SV s1("101", "NVA", true, 3.3);
    SVCNTT s2("102","NVB", true, 3.4,"NGu");
    // s1.show();
    // s2.show();
     SV *p1 = &s1;
     SVCNTT *p2 = &s2;
    p1->show();
    p2->show();
    s2.laptrinh();
    cout << "downcast" << endl;
    //downcast
    p1 = &s2;
    p1->show();
    cout << "upcast" << endl;
    //upcast
    p2 = static_cast<SVCNTT*>(&s1);//ép s1 về kiểu SVCNTT để truyền cho p2
    s1.show();
    p2->show();
    cout << "slicing" << endl;
    //slicing
    SV s3 = s2;
    s3.show();
    SV *p = new SVCNTT("102", "NVB", true, 2.2, "NGU");
    p->show();
    delete p;

    return 0;

    

}