#include<iostream>
#include<iomanip>
#include<vector>
#include <string.h>
using namespace std;

class name 
{
        int age;
        string ten;
        public:
                name()
                {
                        this->age = 0;
                        this->ten = " ";
                }
                friend istream& operator >> (istream& is, name& n)
                {
                        is >> n.age;
                        is >> n.ten;
                        return is;

                }
                friend ostream& operator << (const name& n, ostream& os)
                {
                        os << n.age << " " << n.ten << endl;
                       
                }
};
int main()
{
        name n;
        cin >> n;
        n << cout;
}