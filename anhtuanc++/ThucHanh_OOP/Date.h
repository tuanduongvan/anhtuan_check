#include <iostream>
using namespace std;

class Date
{
    int day;
    int month;
    int year;
    public:
        int get_day();
        void set_day(int);
        int get_month();
        void set_month(int);
        int get_year();
        void set_year(int);
        
        Date();
        bool isLeapYear();
        int monthDay();
        Date nextDay();
        friend istream& operator >> (istream&, Date&);
        friend ostream& operator << (ostream&, const Date&);
};
