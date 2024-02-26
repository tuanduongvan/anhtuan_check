#include "point4D.h"

point4D::point4D(int x, int y, int z, int t)
    :point3D(x, y, z)
{
    cout << "con" << endl;
    this->tval = t;
}

point4D::~point4D()
{
    cout << "huy point4D" << endl;
} 

void point4D::show()
{
    //point::show();
    point3D::show();
    cout << this->tval << endl;
}