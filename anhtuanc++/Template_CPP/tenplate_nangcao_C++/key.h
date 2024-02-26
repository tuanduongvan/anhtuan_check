#include <iostream>
using namespace std;

template<typename K>
class Key
{
    protected:
        K key;
    public:
        Key(K);
        ~Key();
        template<typename K>
        friend ostream& operator << (ostream&, const Key<K>&);
};