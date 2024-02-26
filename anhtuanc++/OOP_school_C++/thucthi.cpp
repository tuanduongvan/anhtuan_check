#include "point3D.h"
 
int  main()
{
    // point p1(1, 2);
    // point p2(1, 2);
    // point p3 = p1 + p2;
    // //point p4 = p1.operator - (p2);
    // point p4 = p1 -p2;
    // //p1 -p2
    // p1.show();
    // p2.show();
    // p3.show();
    // // point::count();
    // cout << p1 << p3;

    // point *p = new point[3];
    // point p3 = p1++;
    // point p4 = ++p2;
    // cout << p1 << p3;
    // cout << p2 << p4;
    // system("pause");
    // return 0;
    // point p1(1, 2);
    // p1.show();
    // point3D p3D(2, 3, 4);
    // p3D.show3D();
    //p3D.show();
    // point4D p4D(1, 2, 3, 4);
    // p4D.show();
    // return 0;

    // SV s1(1, 2022, 2, 6, 100);
    // s1.showSv();
    // s1.showHP();
    // s1.showLSH();
    // s1.HP::show();
    // s1.LSH::show();
    // s1.show();



    point3D p3d(3, 4, 5);
    //ơr đây hai hàm A() và A(int) được point3D kế thừa từ point
    //p3d.A();//error: lớp con kế thừa hai hàm nạp chồng(overload) "hai hàm giống nhau" thì nếu lớp con định nghĩa một hàm thì chỉ dùng được hàm đó, còn các hàm còn lại không dùng được
    p3d.A(9);
}
