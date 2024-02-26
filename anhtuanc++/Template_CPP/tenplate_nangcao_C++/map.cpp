#include "map.h"

template<typename K, typename V, template <typename T> class C >
Map<K, V, C>::Map()
{
    cout << "dung map" << endl;
}

template<typename K, typename V, template <typename T> class C >
Map<K, V, C>::~Map()
{}
template<typename K, typename V, template <typename T> class C >
ostream& operator << (ostream& os, const Map<K, V, C>& m)
{
    os << m.k << "," << m.v << endl;
    return os;
}