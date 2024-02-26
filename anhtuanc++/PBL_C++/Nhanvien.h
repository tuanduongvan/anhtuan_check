// #include "VT.h"
#include <iostream>
#include <iomanip>
using namespace std;

class Nhanvien
{
    string MaNV;
    string TenNV;
    string SDT;
    int So_phieuxuat;
    int So_phieunhap;
    string ngaylamviec;
    public:
        Nhanvien();
        ~Nhanvien();
        string get_MaNV();
        void Nhap_NV();
        string get_ngay();
        friend istream& operator >> (istream&, Nhanvien&);
        friend ostream& operator << (ostream&, const Nhanvien&);
        friend ostream& operator << (const Nhanvien&, ostream&);
        friend class QLVT;
        friend class QLNV;

};
