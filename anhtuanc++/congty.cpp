#include<iostream>
#include<string>
using namespace std;

class NhanVien{
    private:
        string ten, diachi;
    public:
        NhanVien(){
            ten = "";
            diachi = "";
        }
    friend istream& operator >> (istream& is, NhanVien& a);
    friend ostream& operator << (ostream& os, NhanVien& a);
};

istream& operator >> (istream& is, NhanVien& a){
    getline(is, a.ten);
    getline(is, a.diachi);
    return is;
}

ostream& operator << (ostream& os, NhanVien& a){
    os <<  a.ten << " " << a.diachi << " " ;
    return os;
}

class nvkt : public NhanVien{
    private:
        string nganh;
        int sangkien; 
    public:
        nvkt(){
            nganh = "";
            sangkien = 0;
        }
    friend istream& operator >> (istream& is, nvkt& a);
    friend ostream& operator << (ostream& os, nvkt& a);
};

istream& operator >> (istream& is, nvkt& a){
    is >> (NhanVien)a;
    getline(is, a.nganh);
    is >> a.sangkien;
    return is;
}

ostream& operator << (ostream& os, nvkt& a){
    os << (NhanVien)a << " " << a.nganh << " " << a.sangkien << " ";
    return os;
}

class nvtk : public NhanVien{
    private:
        string ngoaingu;
        int baocao;
    public:
        nvtk(){
            ngoaingu = "";
            baocao = 0;
        }
    friend istream& operator >> (istream& is, nvtk& a);
    friend ostream& operator << (ostream& os, nvtk& a);
};

istream& operator >> (istream& is, nvtk& a){
    getline(is, a.ngoaingu);
    is >> a.baocao;
    return is;
}

ostream& operator << (ostream& os, nvtk& a){
    os << a.ngoaingu << " " << a.baocao << " ";
    return os;
}

int main(){
    nvkt a;
    cin >> a;
    cout << a;
}


