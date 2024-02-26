//#include "QLNV.h"
#include "QLVT.h"
#include "fstream"
#include<string>

int main()
{
    cout << endl;
    cout << "----------------------------------------" << endl;
    cout << "SAN PHAM PBL2: DU AN CO SO LAP TRINH" << endl;
    cout << "DE TAI: QUAN LY VAT TU" << endl;
    cout << "GIANG VIEN HUONG DAN: Do Thi Tuyet Hoa" << endl;
    cout << "SINH VIEN THUC HIEN: " << endl;
    cout << "     Nguyen Viet Tu       LOP: 22T_NHAT1" << endl;
    cout << "     Le Anh Tuan          LOP: 22T_NHAT1" << endl;
    cout << "----------------------------------------" << endl << endl;
        QLVT ql_vt;
        ifstream ip1("QUAN_LY.txt", ios::in);
        ofstream op1("OP_QUANLY.txt", ios::app);
        op1 << "-----------------------------------------------------------------------------------------------------------" << endl;
        op1 << "|" << "MA_VT" << setw(4) << "|" << setw(8) << "TEN_VT" << setw(5) << "|" << setw(10) << "MA_LoaiVT" << setw(3) << "|" <<
            setw(10) << "Ngay_Nhap" << setw(3) << "|" << setw(10) << "Don_Vi" << setw(5) << "|" << setw(10) << "MA_NSX" << setw(5) << "|" << setw(10) << "So_Luong" << setw(3) << "|" << setw(10) << "Don_Gia" << setw(5) << "|" << endl;
        op1 << "-----------------------------------------------------------------------------------------------------------" << endl;
        while (!ip1.eof())
        {
            VT newvt;
            ip1 >> newvt;
            if (newvt.getma() != "")
            {
                op1 << newvt;
                ql_vt.Add(newvt);
            }
            else break;
        }
        ip1.close();
        op1.close();

        QLNSX ql_nsx;
        ifstream ip2("NSX.txt", ios::in);
        ofstream op2("OP_NSX.txt", ios::app);
        op2 << "-----------------------" << endl;
        op2 << "|MA_NSX" << setw(2) << "|" << setw(11) << "TEN_NSX" << setw(3) << "|" << endl;
        op2 << "-----------------------" << endl;
        while (!ip2.eof())
        {
            NSX newnsx;
            ip2 >> newnsx;
            if (newnsx.get_MANSX() != "")
            {
                op2 << newnsx;
                ql_nsx.Add_NSX(newnsx);
            }
            else break;
        }
        ip2.close();
        op2.close();


        QL_LoaiVT ql_lvt;
        ifstream ip3("LoaiVt.txt", ios::in);
        ofstream op3("OP_LoaiVT.txt", ios::app);
        op3 << "---------------------------" << endl;
        op3 << "|MA_LoaiVT" << setw(2) << "|" << setw(12) << "TEN_LoaiVT" << setw(3) << "|" << endl;
        op3 << "---------------------------" << endl;
        while (!ip3.eof())
        {
            LoaiVT newlvt;
            ip3 >> newlvt;
            if (newlvt.get_MA_LoaiVT() != "")
            {
                op3 << newlvt;
                ql_lvt.Add_LoaiVT(newlvt);
            }
            else break;
        }
        ip3.close();
        op3.close();

    QLNV ql_nv;
    ifstream ip4("NHAN_VIEN.txt", ios::in);
    while(!ip4.eof())
    {
        Nhanvien newnv;
        ip4 >> newnv;
        if (newnv.get_MaNV() != "")
        {
            ql_nv.AddNV(newnv);
        }
        else break;
    }
    ip4.close();

    int lua_chon;
    string chon = "co";
    while (chon == "co")
    {
        cout << "----------------------MENU----------------------------------" << endl;
        cout << "|1.   IN RA CAC VAT TU HIEN CO TRONG KHO                   |" << endl;
        cout << "------------------------------------------------------------" << endl;
        cout << "|2.   NHAP VAT TU VAO KHO                                  |" << endl;
        cout << "------------------------------------------------------------" << endl;
        cout << "|3.   XUAT KHO                                             |" << endl;
        cout << "------------------------------------------------------------" << endl;
        cout << "|4.   XOA CAC VAT TU CO SO LUONG = 0 TRONG KHO             |" << endl;
        cout << "------------------------------------------------------------" << endl;
        cout << "|5.   TIM KIEM NHAN VIEN THEO MA_NV DUOC CUNG CAP          |" << endl;
        cout << "------------------------------------------------------------" << endl;
        cout << "|6.   THEM MOI VAT TU                                      |" << endl;
        cout << "------------------------------------------------------------" << endl;
        cout << "|7.   THEM MOI NHAN VIEN                                   |" << endl;
        cout << "------------------------------------------------------------" << endl;
        cout << "|8.   THONG KE VAT TU                                      |" << endl;
        cout << "------------------------------------------------------------" << endl;
        cout << "NHAP LUA CHON CUA BAN: ";
        cin >> lua_chon;
        switch (lua_chon)
        {
        case 1:
            cout << endl << "CAC NHA SAN XUAT DANG DUOC QUAN LY" << endl;
            ql_nsx.show_nsx();
            cout << endl << "CAC LOAI VAT TU DANG DUOC QUAN LY" << endl;
            ql_lvt.show_lvt();
            cout << endl << "                                CAC VAT TU HIEN CO TRONG KHO" << endl;
            ql_vt.Show();
            break;
        case 2:
            ql_vt.PHIEUNHAP(ql_nsx, ql_lvt, ql_nv);
            cout << endl << "VAT TU BAN VUA NHAP DA DUOC CAP NHAT!!!" << endl;
            // cout << endl << "                                CAC VAT TU HIEN CO TRONG KHO" << endl;
            // ql_vt.Show();
            break;
        case 3:
            ql_vt.PHIEUXUAT(ql_nv);
            // cout << endl << "                                CAC VAT TU CON LAI TRONG KHO" << endl;
            // ql_vt.Show();
            break;
        case 4:
            ql_vt.Xoa();
            cout << endl << "                                CAC VAT TU CON LAI TRONG KHO" << endl;
            ql_vt.Show();
            break;
        case 5:
            cout << "                      NHAN VIEN CAN TIM" << endl;
            ql_nv.Tim_NV();
            break;
        case 6:
            ql_vt.NHAPMOI(ql_nsx, ql_lvt);
            cout << "CAC VAT TU BAN VUA NHAP DA DUOC CAP NHAT!!!" << endl;
            ql_vt.Show();
            break;
        case 7:
            ql_nv.Them_NV();
            cout << "NHAN VIEN DA DUOC CAP NHAT!!" << endl;
            ql_nv.Show_NV();
            break;
        case 8:
            ql_vt.THONGKEVATTU();
            break;
        }
        cout << "BAN CO MUON TIEP TUC CHUONG TRINH: "; cin >> chon;
    }

    ql_vt.OIP(ql_nv);

    return 0;
}

