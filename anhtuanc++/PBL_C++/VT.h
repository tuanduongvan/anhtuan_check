#include "QLNSX.h"
#include "QL_LoaiVT.h"
#include<iostream>
#include<string>
using namespace std;
class VT
{
    private:
        string ma;
        string ten;
        string ngaynhap;
        string donvi;//tan,cai,bao
        string maNSX;
        string maloaivt;
        int soluong;
        int dongia;
    public:
        VT();
        void Nhap(QLNSX&, QL_LoaiVT&);
        string getma();
        friend istream& operator >> (istream& is, VT&);
        friend ostream& operator << (ostream& os,const VT& p);
        friend ostream& operator << (const VT& p, ostream& os);
        friend class QLVT;
};
