#include "complex.h"

int main()
{
    //khoi tao doi tuong cpmplex
    Complex p1;
    Complex p2;
    cout << "nhap p1 " << endl;
    cin >> p1; 
    //dung ham set
    p1.set(5.2, 6.4);
    cout << "nhap p2 " << endl;
    cin >> p2;
    //cong
    p1.Addition(p2);
    cout << "p1 sau khi duoc cong: ";
    cout << p1;
    //tru
    p2.Subtraction(p1);
    cout << "p2 sau khi duoc tru: ";
    cout << p2;

    return 0;
}