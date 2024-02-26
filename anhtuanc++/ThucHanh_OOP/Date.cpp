#include "Date.h"

Date::Date()
{
    this->day = 0;
    this->month = 0;
    this->year = 0;
}

int Date::get_day()
{
    return this->day;
}

int Date::get_month()
{
    return this->month;
}

int Date::get_year()
{
    return this->year;
}

void Date::set_day(int day)
{
    this->day = day;
}

void Date::set_month(int month)
{
    this->month = month;
}

void Date::set_year(int year)
{
    this->year = year;
}

istream& operator >> (istream& is, Date& d)
{
    cout << "nhap ngay: ";is >> d.day;
    cout << "nhap thang: ";is >> d.month;
    cout << "nhap nam: " ;is >> d.year;
    return is;
}

ostream& operator << (ostream& os, const Date& d)
{
    os << d.day << "/" << d.month << "/" << d.year << endl;
    return os;
}
bool Date::isLeapYear()
{
    return (this->year % 4 == 0 ) ? true : false;  
}

int Date::monthDay()
{
    if (0 < this->month <= 7)
    {
        if (this->month == 2)
        {
            if (this->isLeapYear())
                return 29;
            else return 28;
        }
        else 
        {
            if (this->month % 2 == 0)
                return 30;
            else return 31;
        }
    }
    else if (7 < this->month <= 12)
        {
            if (this->month % 2 == 0)
                    return 31;
            else return 30;
        }
        else cout << "Thang khong hop le!!" << endl;
}

Date Date::nextDay()
{
    this->day++;
    if (this->day <= this->monthDay())
    {
        return *this;
    }
    else 
    {
        this->day = 1;
        this->month++;
        return *this;
    }
}