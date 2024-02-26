#include "matrix.h"
int main()
{
    matrix m1(3, 4, 2);
    m1(0, 2) = 9;
    m1.show();
    cout << m1;
    return 0;
}