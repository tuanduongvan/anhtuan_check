#include <iostream>
#include <string>
using namespace std;
class NSX 
{
    private:
        string MA_NSX;
        string Ten_NSX;
    public:
        NSX();
        string get_MANSX();
        void NhapNSX();
        friend istream& operator >> (istream&, NSX&);
        friend ostream& operator << (ostream&, const NSX&);
        friend ostream& operator << (const NSX&, ostream&);
        friend class VT;//chu y o day
};