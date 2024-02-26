#include<iostream>
using namespace std;
//template<typename T>//khuôn mẫu lớp 
template<typename T>
class Vector 
{
    private:
        T *p;
        int size;
    public:
         Vector();
         ~Vector();
         //Vector(const Vector&);
         //void Show();
        //  friend ostream& operator << (ostream&, const Vector&);
        // int& operator [] (const int&);
        // const Vector& operator = (const Vector&);
        //T& operator [] (const int&);
        template<typename K>
        friend ostream& operator << (ostream&, const Vector<K>& );
};