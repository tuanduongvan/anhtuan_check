#include "SV.h"
class SVCNTT : public SV  
{
    private:
        string lt; 
    public:
        SVCNTT(string = "", string = "", bool = true, double = 0, string = "");
        virtual ~SVCNTT();
        void laptrinh();
        void show();
        friend ostream& operator << (ostream&, const SVCNTT&);
        const SVCNTT& operator = (const SVCNTT&);

};