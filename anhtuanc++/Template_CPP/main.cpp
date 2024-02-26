#include<iostream>
using namespace std;

template<typename T>//khuôn mẫu hàm, chỉ có tác dụng đối với hàm kề sau nó
void  HV(T &a, T &b)
{
    T t = a;
    a = b;
    b = t;
    cout << "goi ham khuon mau" << endl;
}


template<typename T, typename U>
void B(T x, U y)
{
    cout << x <<","<< y << endl;
}

void HV(int a, int b)
{
    int t = a;
    a = b;
    b = t;
    cout << "goi ham" << endl;

}

int main()
{
    int x = 2, y = 4;
    HV<int>(x, y);//gọi tường minh sẽ gọi trực tiếp đến khuôn mẫu hàm
    double a = 1.1, b = 2.2;
    B<int, int>(x, y);
    B<double, double>(a, b);
    HV<double>(a, b);
    HV(x, y);//gọi ngầm định thì ưu tiên gọi đến hàm
    cout << x <<"," << y << endl;
    cout << a << "," << b << endl;

    return 0;
}