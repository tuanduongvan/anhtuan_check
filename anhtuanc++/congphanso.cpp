#include<iostream>
using namespace std;
int ucln(int a, int b){
    if (b == 0) return a;
    return ucln(b, a % b);
}

int bcnn(int a, int b){
    return (a*b/ucln(a,b));
} 

class PhanSo{
    private:
        int tu, mau;
    public:
        PhanSo(int tu, int mau){
           this->tu = tu;
            this->mau = mau;
        }
        void RutGon(){
            int x = ucln(tu, mau);
            tu = tu / x;
            mau = mau / x;
        }
        PhanSo Tong(PhanSo p){
            int a = bcnn(mau, p.mau);
            int _tu = tu *(a / mau) + p.tu * (a / p.mau);
            PhanSo tong(_tu, a);
            tong.RutGon();
            return tong;
        } 


     friend istream& operator >> (istream& is, PhanSo& p);
     friend ostream& operator << (ostream& os,const  PhanSo& p);
    //  PhanSo operator + (const PhanSo& p){
    //      int a = bcnn(mau, p.mau);
    //         int _tu = tu *(a / mau) + p.tu * (a / p.mau);
    //         PhanSo tong(_tu, a);
    //         tong.RutGon();
    //         return tong;
    // }
    PhanSo& operator = (const PhanSo& p){
        this->tu = p.tu;
        this->mau = p.mau;
        return *this;
    }
};

    istream& operator >> (istream& is, PhanSo& p){
        cout << "nhap tu: "; is >> p.tu;
        cout << "nhap mau: "; is >> p.mau;
        return is;
    }

    ostream& operator << (ostream& os,const  PhanSo& p ){
        os << p.tu << "/" << p.mau;
        return os;
    }
    
    
 int main() {
    PhanSo p(1,1), q(1,1);
    cin >> p >> q;
    cout << p << endl << q  << endl; 
    cout << p.Tong(q);
    // cout << p + q;
    system ("pause");
    return 0;
}