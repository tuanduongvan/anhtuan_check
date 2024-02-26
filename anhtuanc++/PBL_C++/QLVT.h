#include "QLNV.h"
#include "VT.h"
#include <vector>
#include <iomanip>
class QLVT 
{
    private: 
        VT *p;
        int length;
        string Ma_NV;
    public: 
        QLVT();
        ~QLVT();
        void Add(const VT&);
        //void Update(int);
        int Vitri(VT);
        // void Remove(VT&);
        void Show();
        VT& operator [] (const int&);
        friend ostream& operator << (ostream&, const QLVT&);
        void PHIEUNHAP(QLNSX&, QL_LoaiVT&, QLNV&);
        void NHAPMOI(QLNSX&, QL_LoaiVT&);
        void PHIEUXUAT(QLNV&);
        void OIP(QLNV&);
        void Removeat(const int&);
        void Xoa();
        void THONGKEVATTU();
        //void input();1
        
};
