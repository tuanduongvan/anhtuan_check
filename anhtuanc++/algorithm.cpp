#include<iostream>
using namespace std;
class sinhvien{
    private:
         string id, name;
         double gpa;
    public:
         void dihoc();
         void noi();
         sinhvien();
         sinhvien(string, string, double);
         ~sinhvien();
         friend void changesinhvien(sinhvien&);

};
void changesinhvien(sinhvien& a){
    a.id = 1111;
}
sinhvien::sinhvien(){
    cout <<"ham tao mac dinh" << endl;
    id = "3";
    name = "nguyen van a";
    gpa = 0.0;

}
void sinhvien::dihoc(){
    cout <<"di hoc\n";

}

void sinhvien::noi(){
    cout <<"di hoc\n";
}

sinhvien::sinhvien(string ma, string ten, double diem ){
    id = ma;
    name = ten;
    gpa = diem;

}
sinhvien::~sinhvien(){
    cout << "ket thuc";
}
int main(){
    sinhvien x;
    changesinhvien(x);
    x.dihoc();
    x.noi();
    
}
