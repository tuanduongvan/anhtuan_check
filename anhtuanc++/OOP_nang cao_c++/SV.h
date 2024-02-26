#include <iostream>
using  namespace std;
class SV
{
    protected:
        string MSSV;
        string name;
        bool gender;
        double dtb;
    public:
        SV(string = "", string = "", bool = true, double = 0.0);
        virtual ~SV();
        friend ostream& operator << ( ostream&, SV&);
        virtual void show();
        virtual const SV& operator = (const SV&);


};