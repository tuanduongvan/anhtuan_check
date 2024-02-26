#include "QLVT.h"
#include <fstream>
using namespace std;

QLVT::QLVT()
{
    this->p = NULL;
    this->length = 0;
    this->Ma_NV = "";
}

QLVT::~QLVT()
{
    delete this->p;
}

ostream& operator << (ostream& os, const QLVT& v)
{
    for (int i = 0; i < v.length; i++)
    {
        os << *(v.p + i) << endl;
    }
    return os;
}

VT& QLVT::operator [] (const int& i)
{
    VT ngu;
    return (0 <= i && i < this->length) ? *(this->p + i) : ngu;
}
void QLVT::Add(const VT& v)
{
    if (this->length == 0)
    {
        this->p = new VT[this->length + 1];
        *(this->p + this->length) = v;
    }
    else
    {
        VT* temp = new VT[this->length];
        for (int i = 0; i < this->length; i++)
        {
            *(temp + i) = *(this->p + i);
        }
        delete[] this->p;
        this->p = new VT[this->length + 1];
        for (int i = 0; i < this->length; i++)
        {
            *(this->p + i) = *(temp + i);
        }
        delete[] temp;
        *(this->p + this->length) = v;
    }
    this->length++;
}

int QLVT::Vitri(VT v)
{
    int index = -1;
    for (int i = 0; i < this->length; i++)
    {
        if (((*this)[i]).ma == v.ma)
        {
            index = i;
        }
        break;
    }
    return index;
}

void QLVT::Removeat(const int& index)
{
     for(int b = index; b < this->length - 1; b++)
    {
        *(this->p + b) = *(this->p + b + 1);
    }
    this->length--;
}


void QLVT::Xoa()
{
    int dem = 0;
    for (int a = 0; a < this->length; a++)
    {
        if ((*this)[a].soluong == 0)
        {
            this->Removeat(a);
            dem++;
        }
    }
    if (dem != 0)
    {
        ofstream op("QUAN_LY.txt", ios::out);
        ofstream o("OP_QUANLY.txt", ios::out);
        this->p[0] << op;
        o << this->p[0];
        o.close();
        op.close();
        ofstream op1("QUAN_LY.txt", ios::app);
        ofstream o1("OP_QUANLY.txt", ios::app);
        for (int a = 1; a < this->length; ++a)
        {
            this->p[a] << op1;
            o1 << this->p[a];
        }
        op1.close();
        o1.close();
    }

    if (dem == 0)
        cout << endl << "KHONG TON TAI VAT TU CO SO LUONG = 0 TRONG KHO!!!" << endl;
}

void QLVT::Show()
{
    cout << "-----------------------------------------------------------------------------------------------------------" << endl;
    cout << "|" << "MA_VT" << setw(4) << "|" << setw(8) << "TEN_VT" << setw(5) << "|" << setw(10) << "MA_LoaiVT" << setw(3) << "|" <<
    setw(10) << "Ngay_Nhap" << setw(3) << "|" << setw(10) << "Don_Vi" << setw(5) << "|" << setw(10) << "MA_NSX" << setw(5) << "|" << setw(10) << "So_Luong" << setw(3) << "|" << setw(10) << "Don_Gia" << setw(5) << "|" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < this->length; i++)
    {
        cout << *(this->p + i);
    }
}

void QLVT::PHIEUNHAP(QLNSX& qlnsx, QL_LoaiVT& qlvt, QLNV& qlnv)
{
    int value = -1;
    cout << "Nhap MA_NV cua ban: ";
    while(true)
    {
    cin >> this->Ma_NV;
        for (int i = 0; i < qlnv.length_nv; i++)
        {
            if (this->Ma_NV == qlnv.p[i].MaNV)
            {
                value = i;
                cout << "MOI BAN NHAP!!!" << endl;
                break;
            }
        }

        if (value == -1)
        {
            cout << "MA_NV ban vua nhap khong hop le! " << endl << "Nhap lai MA_NV: ";
        }
        if (value != -1)
            break;
    }
    string ngaynhap;
    cout << "Ngay nhap: ";
    cin >> ngaynhap;
    int so_vt = 0;
    cout << "So vat tu ban muon nhap vao: ";
    while(true)
    {
        cin >> so_vt;
        if (so_vt <= 0)
            cout << "so vat tu khong hop le!!!" << endl << "nhap lai: ";
        else break;

    }
    vector<pair<string, int>> list1;
    for (int j = 0; j < so_vt; j++)
    {
        VT newvt;
        cout << endl << "nhap maVT: ";
        while(true)
        {
            cin >> newvt.ma;
            int dem = 0;
            for (int i = 0; i < this->length; i++)
            {
                if (newvt.ma == this->p[i].ma)
                {
                    dem = 1;
                        cout << "nhap so luong VT nhap vao: ";
                        while(true)
                        {
                            cin >> newvt.soluong;
                            if (newvt.soluong <= 0)
                                cout << "So luong khong hop le!" << endl << "nhap lai: ";
                            else break;
                        }
                        list1.push_back({newvt.ma, newvt.soluong});
                        this->p[i].soluong += newvt.soluong;
                        this->p[i].ngaynhap = ngaynhap;
                        break;
                }
            }
            if (dem == 1)
                break;
            if (dem == 0)
                cout << "maVT khong ton tai!" << endl << "nhap lai: ";
        }
    }
    qlnv.p[value].So_phieunhap = qlnv.p[value].So_phieunhap + 1;
    qlnv.p[value].ngaylamviec = ngaynhap;
    //////
    {
        ofstream op("QUAN_LY.txt", ios::out);
        ofstream o("OP_QUANLY.txt", ios::out);
        this->p[0] << op;
        o << this->p[0];
        o.close();
        op.close();
        ofstream op1("QUAN_LY.txt", ios::app);
        ofstream o1("OP_QUANLY.txt", ios::app);
        for (int a = 1; a < this->length; ++a)
        {
            this->p[a] << op1;
            o1 << this->p[a];
        }
        op1.close();
        o1.close();
    }
    cout << "                           PHIEU NHAP                " << endl;
    cout << "-------------------------------------------------------------------------------------" << endl;
    cout << "NGAY NHAP KHO: "<< ngaynhap << endl;
    cout << "-------------------------------------------------------------------------------------" << endl;
    cout << "STT" << setw(5) << "|" << setw(9) << "MAVT" << setw(5) << "|" << setw(10) << "TENVT" << setw(5) << "|" << setw(12) << "SOLUONG" <<
        setw(5) << "|" << setw(11) << "DONGIA" << setw(5) << "|" /*<< setw(11) << "NGAYNHAP" << setw(5) << "|" */<< setw(10) << "Ma_NV" << setw(5) << "|" << endl; 
    cout << "-------------------------------------------------------------------------------------" << endl;
    
    for (int i = 0; i < list1.size(); i++)
    {
        for (int j = 0; j < this->length; j++)
        {
            if (list1[i].first == this->p[j].ma)
            {
                cout << i + 1 << setw(7) << "|" << setw(9) << this->p[j].ma << setw(5) << "|" << setw(10) << this->p[j].ten << setw(5) << "|" << setw(12) << list1[i].second <<
                    setw(5) << "|" << setw(11) << this->p[j].dongia << setw(5) << "|" << setw(9) << this->Ma_NV << setw(6) << "|" << endl;
                cout << "-------------------------------------------------------------------------------------" << endl;
            }
        }
    }

}

void QLVT::NHAPMOI(QLNSX& ql_nsx, QL_LoaiVT& ql_lvt)
{
    string ngaynhap;
    cout << "Ngay nhap: ";
    cin >> ngaynhap;
    int so_vt = 0;
    cout << "So vat tu ban muon nhap vao: ";
    while(true)
    {
        cin >> so_vt;
        if (so_vt <= 0)
            cout << "so vat tu khong hop le!!!" << endl << "nhap lai: ";
        else break;

    }
    for (int j = 0; j < so_vt; j++)
    {
        VT newvt;
        cout << endl << "nhap maVT: ";
        //T:
        while(true)
        {
            cin >> newvt.ma;
            int dem = 0;
            for (int i = 0; i < this->length; i ++)
            {
                if(newvt.ma == this->p[i].ma)
                {
                    dem = 1;
                    cout << "MA DA TON TAI!!!" << endl;
                    cout << "NHAP LAI MA VT: ";
                    break;
                }
            }
            if (dem == 0)
            {
                break;
            }
        }
            newvt.ngaynhap = ngaynhap;
            newvt.Nhap(ql_nsx, ql_lvt);
            this->Add(newvt);
            {
                ofstream op3("OP_QUANLY.txt", ios::app);
                ofstream op("QUAN_LY.txt", ios::app);
                op3 << newvt;
                //
                op << endl;
                newvt << op;
                op3.close();
                op.close();
            }
           
    }
}

void QLVT::PHIEUXUAT(QLNV& qlnv)
{
    int value = -1;
    cout << "Nhap MA_NV cua ban: ";
    while(true)
    {
        cin >> this->Ma_NV;
        for (int i = 0; i < qlnv.length_nv; i++)
        {
            if (this->Ma_NV == qlnv.p[i].MaNV)
            {
                value = i;
                cout << "MOI BAN NHAP!!!" << endl;
                break;
            }
        }

        if (value == -1)
        {
            cout << "MA_NV ban vua nhap khong hop le! " << endl << "Nhap lai MA_NV: ";
        }
        if (value != -1)
            break;
    }
    string ngay;
    cout << "Ngay xuat kho: "; cin >> ngay;
    int dem;
    cout << "Nhap vao so luong vat tu can xuat kho" << endl;
    while(true)
    {
        cin >> dem;
        if (dem <= 0)
            cout << "so vat tu khong hop le!!!" << endl << "nhap lai: ";
        else break;

    }
    string ma;
    int soluong;
    vector<pair<string, int>> list;
    cout << "Nhap vao maVT va soluong vat tu xuat kho:" << endl;
    for (int i = 0; i < dem; i++)
    {
        cout << "ma: ";
        while(true)
        {
            cin >> ma;
            int temp = 0;
            for(int i = 0; i < this->length; i++)
            {
                if (this->p[i].ma == ma)
                    {
                        temp = 1;
                        break;
                    }
            }
            if (temp == 1)
                break;
            if (temp == 0)
                cout << "Ma vua nhap khong ton tai!!!" << endl << "Nhap lai ma: ";
        }
        cout << "So luong: ";
        while(true)
        {
            cin >> soluong;
            if (soluong < 0)
            {
                cout << "so luong ban vua nhap khong hop le!" << endl << "moi nhap lai: ";
            }
            else break;
        }
        //
        for (int j = 0; j < this->length; j++)
        {
            if ((*this)[j].ma == ma)
            {
                if (soluong > this->p[j].soluong)
                {
                    cout << "SO LUONG VAT TU BAN VUA NHAP VUOT QUA SO LUONG HIEN TAI CO TRONG KHO!" << endl;
                    cout << "HAY NHAP LAI SO LUONG VAT TU THU " << i + 1 << " : ";
                    int newsoluong;
                    cin >> newsoluong;
                    list.push_back({ ma, newsoluong });
                }
                //
                else list.push_back({ ma, soluong });
                break;
            }

        }
    }


    for (int i = 0; i < list.size(); i++)
    {
        for (int j = 0; j < this->length; j++)
        {
            if (list[i].first == this->p[j].ma)
            {
                if (list[i].second > this->p[i].soluong)
                {
                    cout << "SO LUONG VAT TU THU " << i + 1 << " " << "VUOT QUA SO LUONG HIEN TAI CO TRONG KHO!" << endl;
                    list.erase(list.begin() + i);
                    break;
                }
                else
                {
                    this->p[j].soluong -= list[i].second;
                    break;
                }
            }
        }
    }
    {
        ofstream op("QUAN_LY.txt", ios::out);
        ofstream o("OP_QUANLY.txt", ios::out);
        this->p[0] << op;
        o << this->p[0];
        o.close();
        op.close();
        ofstream op1("QUAN_LY.txt", ios::app);
        ofstream o1("OP_QUANLY.txt", ios::app);
        for (int a = 1; a < this->length; ++a)
        {
            this->p[a] << op1;
            o1 << this->p[a];
        }
        op1.close();
        o1.close();
    }
    cout << "-------------------------------PHIEU XUAT------------------------------------------------" << endl;
    cout << "NGAY XUAT KHO: " << ngay << endl;
    cout << "-----------------------------------------------------------------------------------------" << endl;
    cout << "STT" << setw(5) << "|" << setw(9) << "MAVT" << setw(5) << "|" << setw(10) << "TENVT" << setw(5) << "|" << setw(12) << "SOLUONG" <<
        setw(5) << "|" << setw(11) << "DONGIA" << setw(9) << "|" << setw(10) << "MA_NV" << setw(5) << "|" << endl;
    cout << "-----------------------------------------------------------------------------------------" << endl;
    unsigned int S;
    unsigned int  TT = 0;
    for (int i = 0; i < list.size(); i++)
    {
        for (int j = 0; j < this->length; j++)
        {
            S = 0;
            if (list[i].first == this->p[j].ma)
            {
                S = list[i].second * this->p[j].dongia;
                cout << i + 1 << setw(7) << "|" << setw(9) << this->p[j].ma << setw(5) << "|" << setw(10) << this->p[j].ten << setw(5) << "|" << setw(12) << list[i].second <<
                    setw(5) << "|" << setw(11) << S << setw(9) << "|" << setw(10) << this->Ma_NV << setw(5) << "|" << endl;
                cout << "-----------------------------------------------------------------------------------------" << endl;
                TT += S;
            }
        }
    }
    cout << "|TONG SO TIEN:" << setw(10) << TT << "                                                                |" << endl;
    cout << "-----------------------------------------------------------------------------------------" << endl;
    qlnv.p[value].So_phieuxuat = qlnv.p[value].So_phieuxuat + 1;
    qlnv.p[value].ngaylamviec = ngay;
}

void QLVT::THONGKEVATTU()
{
    int lua_chon;
    cout << "-------------------------------------------------------" << endl;
    cout << "| 1.THONG KE VAT TU THEO LOAI VAT TU                  |" << endl;
    cout << "-------------------------------------------------------" << endl;
    cout << "| 2.THONG KE VAT TU THEO NHA SAN XUAT                 |" << endl;
    cout << "-------------------------------------------------------" << endl;
    cout << "nhap lua chon :" ; cin >> lua_chon;
    switch(lua_chon)
    {
        case 1:
            {
            VT ma_vt;
            int dem=0;
            cout << "nhap ma loai vat tu muon thong ke:" ;
            while (true)
            {
                cin >> ma_vt.maloaivt;
                for (int i = 0; i < this->length; i ++)
                {
                    if(ma_vt.maloaivt == this->p[i].maloaivt)
                    {   
                            cout << "-----------------------"<< endl;
                            cout << "| MA LOAI VAT TU : " <<ma_vt.maloaivt<< "|" << endl;
                            cout << "-----------------------------------------------------------------------------------------------------" << endl;
                            cout << "|" << "MA_VT" << setw(4) << "|" << setw(12) << "TEN_VT" << setw(8) << "|" <<
                            setw(10) << "Ngay_Nhap" << setw(3) << "|" << setw(10) << "Don_Vi" << setw(5) << "|" << setw(10) << "MA_NSX" << setw(5) << "|" << setw(10) << "So_Luong" << setw(3) << "|" << setw(10) << "Don_Gia" << setw(5) << "|" << endl;
                            cout << "-----------------------------------------------------------------------------------------------------" << endl;
                        
                        for (int i = 0; i < this->length; i ++)
                        {
                            if(ma_vt.maloaivt == this->p[i].maloaivt)
                            {
                            cout << "|" << p[i].ma << setw(5) << "|" << setw(10) << p[i].ten << setw(10) << "|" <<
                            setw(10) << p[i].ngaynhap << setw(3) << "|" << setw(10) << p[i].donvi << setw(5) << "|" << setw(10) << p[i].maNSX << setw(5) << "|" << setw(10) << p[i].soluong << setw(3) << "|" << setw(10) << p[i].dongia << setw(5) << "|" << endl;
                            cout << "-----------------------------------------------------------------------------------------------------" << endl;                  
                            }
                        }
                        dem=1;
                        break;
                    }
                }
                if(dem==0)
                {   
                    cout << "tim kiem that bai." << endl;
                    cout << "ma loai vat tu khong ton tai!" << endl;
                    cout << "nhap lai ma loai vat tu muon thong ke : ";
                }
                if(dem==1)
                {
                    break;
                }
            }
            break;
            }
        case 2:
        {
            VT ma_vt;
            int dem=0;
            cout << "nhap ma nha san xuat muon thong ke:" ;
            while (true)
            {
                cin >> ma_vt.maNSX;
                for (int i = 0; i < this->length; i ++)
                {
                    if(ma_vt.maNSX == this->p[i].maNSX)
                    {   
                            cout << "-----------------------"<< endl;
                            cout << "| MA NHA SAN XUAT : " <<ma_vt.maNSX<< "|" << endl;
                            cout << "-----------------------------------------------------------------------------------------------------" << endl;
                            cout << "|" << "MA_VT" << setw(4) << "|" << setw(12) << "TEN_VT" << setw(8) << "|" <<
                            setw(10) << "Ngay_Nhap" << setw(3) << "|" << setw(10) << "Don_Vi" << setw(5) << "|" << setw(10) << "Ma_loai_VT" << setw(5) <<"|"<< setw(10) << "So_Luong" << setw(3) << "|" << setw(10) << "Don_Gia" << setw(5) << "|" << endl;
                            cout << "-----------------------------------------------------------------------------------------------------" << endl;
                        for (int i = 0; i < this->length; i ++)
                        {
                            if(ma_vt.maNSX == this->p[i].maNSX)
                            {
                            cout << "|" << p[i].ma << setw(5) << "|" << setw(10) << p[i].ten << setw(10) << "|" <<
                            setw(10) << p[i].ngaynhap << setw(3) << "|" << setw(10) << p[i].donvi << setw(5) << "|" << setw(10) << p[i].maloaivt << setw(5) << "|" << setw(10) << p[i].soluong << setw(3) << "|" << setw(10) << p[i].dongia << setw(5) << "|" << endl;
                            cout << "-----------------------------------------------------------------------------------------------------" << endl;                  
                            }
                        }
                        dem=1;
                        break;
                    }
                }
                if(dem==0)
                {   
                    cout << "tim kiem that bai." << endl;
                    cout << "ma nha san xuat khong ton tai!" << endl;
                    cout << "nhap lai ma nha san xuat muon thong ke : ";
                }
                if(dem==1)
                {
                    break;
                }
            }
            break;
        }
    }
}

void QLVT::OIP(QLNV& ql)
{
    ofstream op("OP_NHANVIEN.txt", ios::app);
    op << "ngay lam viec: ";
    if (ql.p[0].ngaylamviec != "")
        op << ql.p[0].ngaylamviec << endl;
    else 
        op << ql.p[1].ngaylamviec << endl;
    op << "------------------------------------------------------------------------------------------" << endl;
    op << "|" << "MA_NV" << setw(5) << "|" << setw(20) << "TEN_NV" << setw(5) << "|" << setw(15) << "SDT" 
    << setw(5) << "|" << setw(14) << "So_phieunhap" << setw(3) << "|" << setw(14) << "So_phieuxuat" << setw(3) << "|" <<  endl;
    op << "------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < ql.length_nv; i++)
    {
        op << ql.p[i];
    }
    op.close();
    ofstream o("NHAN_VIEN.txt", ios::out);
    ofstream op1("NHAN_VIEN.txt", ios::app);
    ql.p[0] << o;
    for (int i = 1; i < ql.length_nv; i++)
    {
        ql.p[i] << op1;
    }
    o.close();
    op1.close();
}