#include "key.h"

template<typename K>
Key<K>::Key(K k)
    :key(k)
{}

template<typename K>

Key<K>::~Key()
{}

template<typename K>
ostream& operator << (ostream& os, const Key<K>& k)
{
    os << k.key;
    return os;
}

