#include "LSH.h"
#include "HP.h"
#include<iostream>

using namespace std;

class SV : public LSH, public HP
{
    private:
        int MSSV;
    public:
        SV(int, int , int, int, int);
        ~SV();
        void showSv();
        void show();
};