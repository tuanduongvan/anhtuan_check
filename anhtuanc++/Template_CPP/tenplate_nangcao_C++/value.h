#include <iostream>
using namespace std;

template<typename V>
class Value
{
    protected:
        V value;
    public:
        Value(V);
        ~Value();
        template<typename V>
        friend ostream& operator << (ostream&, const Value<V>&);
};