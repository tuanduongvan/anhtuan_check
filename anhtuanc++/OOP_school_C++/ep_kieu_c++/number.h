#include<iostream>
using namespace std;

class number
{
    private:
        double d;
    public: 
        number(double = 1.1 );
        ~number();
        operator int ();
        operator double ();
         
};