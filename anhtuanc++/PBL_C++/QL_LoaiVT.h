#include "LoaiVT.h"

class QL_LoaiVT
{
    protected:
        LoaiVT *p;
        int length1;
    public:
        QL_LoaiVT();
        ~QL_LoaiVT();
        void Add_LoaiVT(const LoaiVT&);
        void remove(const LoaiVT&);
        int Vitri( LoaiVT);
        void show_lvt();
        LoaiVT&  operator [] (const int&);//chu y  chu y chu y
        friend class VT;//chu y o day
        // friend class Nhanvien;
};