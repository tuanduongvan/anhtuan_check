#include<iostream>
using namespace std;
 class matrix 
 {
    private:
        int **p;
        int row, col;
    public:
        matrix(int = 2, int = 3, int = 1);
        ~matrix();
        void show();
        friend ostream& operator << (ostream&, const matrix&);
        int& operator () (const int&, const int&);
 };