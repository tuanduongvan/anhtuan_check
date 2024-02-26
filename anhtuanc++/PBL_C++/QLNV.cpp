#include "QLNV.h"
#include <iomanip>
#include <fstream>
QLNV::QLNV()
{
    this->p = NULL;
    this->length_nv = 0;
}

QLNV::~QLNV()
{
    delete[] p;
}

Nhanvien& QLNV::operator [] (const int& i)
{
    Nhanvien  NGU;
    return (i >= 0 && i < this->length_nv) ? *(this->p + i) : NGU; 
}

void QLNV::AddNV(const Nhanvien& nv)
{
    if (this->length_nv == 0)
    {
        this->p = new Nhanvien[this->length_nv + 1];
        *(this->p + this->length_nv) = nv;
    }
    else
    {
        Nhanvien* temp = new Nhanvien[this->length_nv];
        for (int i = 0; i < this->length_nv; i++)
        {
            *(temp + i) = *(this->p + i);
        }
        delete[] this->p;
        this->p = new Nhanvien[this->length_nv + 1];
        for (int i = 0; i < this->length_nv; i++)
        {
            *(this->p + i) = *(temp + i);
        }
        delete[] temp;
        *(this->p + this->length_nv) = nv;
    }
    this->length_nv++;
}

int QLNV::ViTri(Nhanvien nv)
{
    int index = -1;
    for (int i = 0; i < this->length_nv; i++)
    {
        if (((*this)[i]).get_MaNV() == nv.get_MaNV())
            index = i;
        break;
    }
    return index;
}

void QLNV::Remove(Nhanvien& nv)
{
    
    int index = ViTri(nv);
    cout << index << endl;
    if (index >= 0)
    {
        for (int i = index; i < this->length_nv - 1; i++)
        {
            *(this->p + i) = *(this->p + i + 1);
        }
        this->length_nv--;
    }
    else
        cout << "NHan vien khong duoc quan ly" << endl;
}

void QLNV::Show_NV()
{
    cout << "------------------------------------------------------------------------------------------" << endl;
    cout << "|" << "MA_NV" << setw(5) << "|" << setw(20) << "TEN_NV" << setw(5) << "|" << setw(15) << "SDT" 
    << setw(5) << "|" << setw(14) << "So_phieunhap" << setw(3) << "|" << setw(14) << "So_phieuxuat" << setw(3) << "|" <<  endl;
    cout << "------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < this->length_nv; i++)
    {
        cout << *(this->p + i) << endl;
    }
}

void QLNV::Tim_NV()
{
    string ma;
    cout << "Nhap MA_Nv can tim: ";
    cin >> ma;
    for (int i = 0; i < this->length_nv; i++)
    {
        if (ma == this->p[i].get_MaNV())
        {
            cout << "------------------------------------------------------------------------------------------" << endl;
    cout << "|" << "MA_NV" << setw(5) << "|" << setw(20) << "TEN_NV" << setw(5) << "|" << setw(15) << "SDT" 
    << setw(5) << "|" << setw(14) << "So_phieunhap" << setw(3) << "|" << setw(14) << "So_phieuxuat" << setw(3) << "|" <<  endl;
    cout << "------------------------------------------------------------------------------------------" << endl;
            cout << *(this->p + i);
            break;
        }
    }
}

void QLNV::Them_NV()
{
    Nhanvien new_nv;
    cout << "Nhap MA_NV: ";
    while(true)
    {
        cin >> new_nv.MaNV;
        int dem = 0;
        for (int i = 0; i < this->length_nv; i++)
        {
            if (new_nv.MaNV == this->p[i].get_MaNV())
            {
                dem = 1;
                cout << "MA DA TON TAI!!!" << endl;
                cout << "NHAP LAI MA_nv: "; 
                break;
            }
        }
        if (dem == 0)
        {
            break;
        }
    }
    new_nv.Nhap_NV();
    this->AddNV(new_nv);
    {
        ofstream op4("OP_NHANVIEN.txt", ios::app);
        op4 << new_nv;
        op4.close();
    }

}