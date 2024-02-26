#include "point3D.h"
class point4D : public point3D
{
    private:
        int tval;
    public:
        point4D(int = 3, int = 3, int = 3, int = 3);
        ~point4D();
        void show();
};