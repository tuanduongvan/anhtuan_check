#include "Nhanvien.h"
#include <iostream>
using namespace std;

class QLNV
{
    Nhanvien *p;
    int length_nv;
    public:
        QLNV();
        ~QLNV();
        void AddNV(const Nhanvien&);
        int ViTri(Nhanvien);
        void Remove(Nhanvien&);
        void Them_NV();
        void Show_NV();
        Nhanvien& operator [] (const int&);
        void Tim_NV();
        friend class QLVT;
};