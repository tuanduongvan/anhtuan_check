#include "SV.h"
class QLSV
{
    private:
        SV *p;
        int length;
    public:
        QLSV();
        ~QLSV();
        void add(const SV&);
        void insert(const SV&, const int&);
        // truyền đối tương SV s vào, tìm trong mảng
        //nếu có phần tử trùng ->thì trả về vị trí phần tử trùng
        //nếu không có trả về giá trị -1
        int indexof(SV);//int indexof(const SV&);
        void remove(SV&);
        void removeat(const int&);
        friend ostream& operator << (ostream&, const QLSV&);
        SV& operator [] (const int&);
        //mssv là thuộc tính khóa chính -> không thay đổi
        void update(const int&);
};