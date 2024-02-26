#include<iostream>

using namespace std;

class EXP
{
    protected:
        string err;
    public:
        EXP(string = "");
        ~EXP();
        friend ostream& operator << (ostream&, const EXP&); 
};       