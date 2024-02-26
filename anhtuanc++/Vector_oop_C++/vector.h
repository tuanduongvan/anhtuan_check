#include<iostream>
using namespace std;
//template<typename T>//khuôn mẫu lớp 
template<typename T, int U>
class Vector 
{
    private:
        T *p;
        U size;
    public:
         Vector();
         ~Vector();
         //Vector(const Vector&);
         void Show();
        //  friend ostream& operator << (ostream&, const Vector&);
        // int& operator [] (const int&);
        // const Vector& operator = (const Vector&);
        T& operator [] (const int&);
        template<typename K, int U>
        friend ostream& operator << (ostream&, const Vector<K, U>& );
};