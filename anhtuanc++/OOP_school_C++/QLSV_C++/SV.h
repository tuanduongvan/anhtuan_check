#include<iostream>
using namespace std;

class SV 
{
    private:
        int mssv;
        bool gender;
        double dtb;
    public:
        SV(int = 0, bool = true,  double = 0.0);
        SV(const SV&);
        ~SV();
        int _mssv();
        friend ostream& operator << (ostream& , const SV&);
        friend istream& operator >> (istream& , SV&);

};