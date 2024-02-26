#include <iostream>
#include <string>
using namespace std;
class LoaiVT
{
    private:
        string MA_LoaiVT;
        string Ten_LoaiVT;
    public:
        LoaiVT();
        string get_MA_LoaiVT();
        void Nhap_loaivt();
        friend istream& operator >> (istream&, LoaiVT&);
        friend ostream& operator << (ostream&, const LoaiVT&);
        friend ostream& operator << (const LoaiVT&, ostream&);
        friend class VT;//chu y o day
};