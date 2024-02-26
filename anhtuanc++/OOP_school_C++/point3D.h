#include"point.h"
class point3D : public point
{
    protected:
        int zval;
    public: 
        point3D(int, int, int);
        ~point3D();
        void show3D();
        void show();
        void A(int);
};
