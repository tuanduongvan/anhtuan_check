#include "NSX.h"

class QLNSX
{
    protected:
        NSX *p;
        int length2;
    public:
        QLNSX();
        ~QLNSX();
        void Add_NSX(const NSX&);
        void remove(NSX&);
        int Vitri(NSX);
        void show_nsx();
        NSX&  operator [] (const int&);//chu y chu y chu y
        friend class VT; //chu y o day
        // friend class Nhanvien;
};
