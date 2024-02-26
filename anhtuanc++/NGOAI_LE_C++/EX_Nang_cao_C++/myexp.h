#include "exp.h"

class myexp : public EXP
{
    private:
        int s;
    public:
        myexp(string = "", int = 0);
        ~myexp();
        friend ostream& operator << (ostream&, const myexp&);

};