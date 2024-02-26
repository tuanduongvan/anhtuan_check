#include "Date.h"

int main()
{
    Date d;
    cin >> d;
    cout << "ngay ban vua nhap: ";
    cout << d;

    //kiem tra nam vua nhap co nhuan hay khong
    if (d.isLeapYear())
        cout << "Nam hien tai la nam nhuan" << endl;
    else cout << "Nam hien tai khong nhuan" << endl;

    //so ngay cua thang hien tai
    cout << "so ngay cua thang hien tai: ";
    int dem = d.monthDay();
    cout << dem << endl;

    //In ra 40 ngay ke tiep tu ngay hien tai
    cout << "40 ngay tiep theo ke tu ngay ban nhap: " << endl;
    for (int i = 0; i < 40; i++)
    {
        d.nextDay();
        cout << "Ngay thu " << i+1 << ": ";
        cout << d;
    }

    return 0;
}