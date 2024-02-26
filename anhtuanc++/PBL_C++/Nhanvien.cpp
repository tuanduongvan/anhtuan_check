#include "nhanvien.h"

Nhanvien::Nhanvien()
{
    this->MaNV = "";
    this->TenNV = "";
    this->SDT = "";
    this->So_phieunhap = 0;
    this->So_phieuxuat = 0;
    this->ngaylamviec = "";
}

Nhanvien::~Nhanvien()
{}

ostream& operator << (ostream& os,const Nhanvien& nv)
{
    os << "|" << nv.MaNV << setw(6) << "|" << setw(20) << nv.TenNV << setw(5) << "|" << setw(15) << nv.SDT 
    << setw(5) << "|" << setw(14) << nv.So_phieunhap << setw(3) << "|" << setw(14) << nv.So_phieuxuat << setw(3) << "|" <<  endl;
    os << "------------------------------------------------------------------------------------------" << endl;
}

ostream& operator << (const Nhanvien& nv, ostream& os)
{
    os << nv.MaNV << " " << nv.TenNV << " " << nv.SDT << " " << nv.So_phieunhap << " " << nv.So_phieuxuat << endl;
    return os;
}

void Nhanvien::Nhap_NV()
{
    cout << "Nhap TEN_NV: ";
    cin >> this->TenNV;
    cout << "Nhap so dien thoai: ";
    cin >> this->SDT;

}

istream& operator >> (istream& is, Nhanvien& nv)
{
    is >> nv.MaNV;
    is >> nv.TenNV;
    is >> nv.SDT;
    is >> nv.So_phieunhap;
    is >> nv.So_phieuxuat;

    return is;
}

string Nhanvien::get_MaNV()
{
    return this->MaNV;
}

string Nhanvien::get_ngay()
{
    return this->ngaylamviec;
}