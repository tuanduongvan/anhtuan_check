#include "point.h"

point::point(int x, int y )
{
    cout << "ong noi" << endl;
    this->xval = x;
    this->yval = y;
}

// point::point(int x, int y)
//     :xval(x), yval(y)
// {
//     this->xval = 4;
//     this->yval = 5;
// }

// point::point(const point& p1)
// {
//     this->xval = p1.xval;
//     this->yval = p1.yval;
// }

point::~point()
{
    cout << "huy point";
}

// void point::TT(int x)
// {
//     this->xval += x;
//     this->yval += x;
// }

void point::show()
{
    cout << "point: " << this->xval << " , " <<this->yval << endl;
}
// void point::count()
//  {
//     cout << point::n <<endl;
//  }

// point operator + (const point& x, const point& y)
//  {
//    //  point p(x.xval + y.xval, x.yval + y.yval);
//    //  return p;
//    return point(x.xval + y.xval, x.yval + y.yval);//tiet kiem bo nho
//  }

//  point point::operator - (const point& p)
//  {
//    //  point p(this->xval - p.xval, this->yval - p.yval);
//    //  return p;
//    return point(this->xval - p.xval, this->yval - p.yval);
//  }

 istream& operator >> (istream& is, point& p)
 {
    is >> p.xval >> p.yval;
    return is;
 }

 ostream& operator << (ostream& os, const point& p)
 {
    os << p.xval <<"," << p.yval << endl;
 }

//  point& point::operator ++ ()
//  {
//     this->xval++;
//     this->yval++;
//     return *this;
//  }

//  const point point::operator ++ (int)
//  {
//     point p =  *this;
//     this->xval++;
//     this->yval++;
//     return p;
//  }

void point::A()
{
    cout << "A " << endl;
}

void point::A(int x)
{
    cout << "point - " << x << endl;
}