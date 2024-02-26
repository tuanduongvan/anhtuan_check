#include<iostream>
using namespace std;

int ucln(int a, int b){
    if (b == 0) return a;
    return ucln(b, a % b);
}

class PhanSo{
    private:
        int tu, mau;
    public:
        PhanSo(int tu, int mau){
            tu = tu;
            mau = mau;
        }
        void rutgon(){
           int a = ucln(tu, mau);
           tu = tu / a;
           mau = mau / a;
        }
        friend istream& operator >> (istream& is, PhanSo& ps);
        friend ostream& operator << (ostream& os, const PhanSo& ps);
};

istream& operator >> (istream& is, PhanSo& ps){
    cout << "nhap tu: "; is >> ps.tu;
    cout << "nhap mau: "; is >> ps.mau;
    return is;
}

ostream& operator << (ostream& os, const PhanSo& ps){
    os << ps.tu << "/" << ps.mau << "\n";
    return os; 
}



int main() {
PhanSo p(1,1);
cin >> p;
p.rutgon();
cout << p;
system ("pause");
return 0;
}