#include "QLSV.h"

int main()
{
    QLSV db;
    SV s1(1, true, 2.3);
    SV s2(2, false, 3.5);
    SV s3(3, true, 3.9);
    db.add(s1);
    db.add(s2);
    db.add(s3);
    cout << db;
    return 0;
}