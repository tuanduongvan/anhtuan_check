#include "value.h"

template<typename V>
Value<V>::Value(V v)
    :value(v)
{}

template<typename V>
Value<V>::~Value()
{}

template<typename V>
ostream& operator << (ostream& os, const Value<V>& v)
{
    os << 
}
