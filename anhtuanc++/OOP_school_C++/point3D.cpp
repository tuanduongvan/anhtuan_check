#include"point3D.h"

point3D::point3D(int x, int y, int z)
    :point(x, y)
{ 
    cout << "cha" << endl;
    this->zval = z;
}

point3D::~point3D()
{
    cout << "huy point3D" << endl;
}

void point3D::show3D()
{
   point::show();
   cout << this->zval << endl;
}

void point3D::show()
{
    cout << "point3D:" << this->xval << "," << this->yval 
    << ", " << this->zval << endl;
}

void point3D::A(int x)
{
    cout << "point3D - " << x << endl;
}