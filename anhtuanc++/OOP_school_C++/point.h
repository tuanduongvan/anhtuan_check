#include<iostream>
using namespace std;
class point
{
    public:
        // static int n;//biến thuộc tính tĩnh
    protected:
        int xval;
        int yval;
    public:
        // static void count(); //hàm thuộc tính tĩnh-> chỉ thao tác được với biến thuộc tính tĩnh
        // point();
        point(int, int);
        // point(const point&);
        ~point();
        // void TT(int );
        virtual void show();
        // friend point operator+(const point&, const point& );
        // point operator - (const point&);
        friend istream& operator >> (istream&, point&);
        friend ostream& operator << (ostream&, const point&);
        //pre-fix
        // const point operator ++ (int);
        // //pro-fix
        // point& operator ++ ();
        void A();
        virtual void A(int);



};