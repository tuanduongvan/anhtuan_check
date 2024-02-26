#include "VT.h"
#include<iostream>
#include<string.h>
#include <fstream>
#include <iomanip>

using namespace std;
VT::VT()
{
    ma = "";
    ten = "";
    maloaivt = "";
    ngaynhap = "";
    donvi = "";
    maNSX = "";
    soluong = 0;
    dongia = 0;
}



void VT::Nhap(QLNSX& qlnsx, QL_LoaiVT& qlvt)
{
    cout << "Nhap TENVT: ";
    cin >> this->ten;
    cout << "Nhap MA_LoaiVT: ";
    cin >> this->maloaivt;
    int temp = 0;
    for (int i = 0; i < qlvt.length1; i ++)
    {
        
        if (this->maloaivt == qlvt.p[i].get_MA_LoaiVT())
        {
            temp = 1;
            break;

        }
    }

    if (temp == 0)
    {
        cout << endl << "MA LOAI VAT TU KHONG TON TAI!" << endl << "CAP NHAT MA LOAI VAT TU!" << endl;
        LoaiVT update_lvt;
        //
        while(true)
        {
            int dem = 0;
            update_lvt.Nhap_loaivt();
            for (int i = 0; i < qlvt.length1; i ++)
            {
                if (update_lvt.MA_LoaiVT == qlvt.p[i].MA_LoaiVT)
                    {
                        dem = 1;
                        break;
                    }
            }
            if (dem == 1)
                cout << "ma da ton tai!!" << endl << "nhap lai: " << endl;
            if (dem == 0)
                break;
        }
        this->maloaivt = update_lvt.MA_LoaiVT;
        qlvt.Add_LoaiVT(update_lvt);
        {
            ofstream op1("OP_LoaiVT.txt", ios::app);
            ofstream op("LoaiVt.txt", ios::app);
            op1 << update_lvt;
            op << endl;
            update_lvt << op;
            op1.close();
            op.close();
        }
        cout << endl << "CAP NHAT THANH CONG MA LOAI VAT TU!" << endl;
    }

    cout << "Nhap Don_vi: ";
    cin >> this->donvi;
    cout << "Nhap MA_NSX: ";
        cin >> this->maNSX;
        int index = 0;
        for (int i = 0; i < qlnsx.length2; i++)
        {
            if (this->maNSX == qlnsx.p[i].get_MANSX())
                {
                    index = 1;
                    break;

                }
        }
        if (index == 0)
                {
                    cout << endl << "MA NHA SAN XUAT KHONG TON TAI!" << endl << "CAP NHAT MA NHA SAN XUAT!" << endl;
                    NSX update_nsx;
                    //
                    while (true)
                    {
                        int dem = 0;
                        update_nsx.NhapNSX();
                        for (int i = 0; i < qlnsx.length2; i++)
                        {
                            if (update_nsx.MA_NSX == qlnsx.p[i].MA_NSX)
                            {
                                dem = 1;
                                break;
                            }
                        }
                        if (dem == 1)
                            cout << "ma da ton tai!!" << endl
                                 << "nhap lai: " << endl;
                        if (dem == 0)
                            break;
                    }
                    this->maNSX = update_nsx.MA_NSX;
                    qlnsx.Add_NSX(update_nsx);
                    {
                        ofstream op2("OP_NSX.txt", ios::app);
                        ofstream op("NSX.txt", ios::app);
                        op2 << update_nsx;
                        op << endl;
                        update_nsx << op;
                        op.close();
                        op2.close();
                    }
                    cout << endl << "CAP NHAT THANH CONG MA NHA SAN XUAT!" << endl;
                }
    

    cout << "Nhap So_luong: ";
    while (true)
    {
        cin >> this->soluong;
        if (this->soluong <= 0)
            cout << "So luong khong hop le!" << endl
                 << "nhap lai: ";
        else
            break;
    }
    // cin >> this->soluong;
    cout << "Nhap Don_gia: ";
     while (true)
    {
        cin >> this->dongia;
        if (this->dongia <= 0)
            cout << "So luong khong hop le!" << endl
                 << "nhap lai: ";
        else
            break;
    }
    // cin >> this->dongia;

}

istream& operator >> (istream& is, VT& p)
{

    is >> p.ma;
    is >> p.ten;
    is >> p.maloaivt;
    is >> p.ngaynhap;
    is >> p.donvi;
    is >> p.maNSX;
    is >> p.soluong;
    is >> p.dongia;
    return is;
}

ostream& operator << (ostream& os, const VT& p)
{
    os << "|" << p.ma << setw(5) << "|" << setw(8) << p.ten << setw(5) << "|" << setw(10) << p.maloaivt << setw(3) << "|" <<
    setw(10) << p.ngaynhap << setw(3) << "|" << setw(10) << p.donvi << setw(5) << "|" << setw(10) << p.maNSX << setw(5) << "|" << setw(10) << p.soluong << setw(3) << "|" << setw(10) << p.dongia << setw(5) << "|" << endl;
    os << "-----------------------------------------------------------------------------------------------------------" << endl;
    return os;
}

ostream& operator << (const VT& p, ostream& os)
{
    os << p.ma << " " << p.ten << " " << p.maloaivt << " " << p.ngaynhap << " " << p.donvi << " " << p.maNSX << " " << p.soluong << " " << p.dongia << " " << endl;
    return os;
}

string VT::getma()
{
    return ma;
}

