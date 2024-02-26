#include <iostream>
using namespace std;

class CSDL
{
    private:
        static CSDL* instance;
    private: 
        CSDL();
        ~CSDL();
    public: 
        static CSDL* get_CSDL()
        {
            if(instance == NULL)
                CSDL();
            return instance;
        }

        void show();
};
