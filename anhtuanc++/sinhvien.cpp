#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class SinhVien{
    private:
        string maSV = "B20DCCN001";
        string hoten, lop;
        float GPA;
        string sinhnhat;
    public:
        SinhVien(){
            hoten = "";
            lop = "";
            sinhnhat = "";
            GPA = 0;
        }
        friend istream& operator >> (istream& is, SinhVien& a);
        friend ostream& operator << (ostream& os, SinhVien& a);

    
};


istream& operator >> (istream& is, SinhVien& a){
    cout << "nhap input ";
    getline(is,a.hoten);
    getline(is,a.lop);
    getline(is,a.sinhnhat);
     if (a.sinhnhat[2] != '/'){
        a.sinhnhat.insert(a.sinhnhat.begin(), '0');
     }
     if (a.sinhnhat[5] != '/'){
        a.sinhnhat.insert(a.sinhnhat.begin() + 3,'0');
     }
    is >> a.GPA;   
    return is;
}

ostream& operator << (ostream& os, SinhVien& a){
    os << a.maSV << " " << a.hoten << " " << a.sinhnhat << " " << a.lop << " ";
    os << fixed << setprecision(2) << a.GPA << endl;
    return os;
    }

int main(){
SinhVien a;
cin >> a;
cout << a;
system("pause");
return 0;
}