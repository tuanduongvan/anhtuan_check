#include<iostream>
using namespace std;

template<typename K, typename V, template <typename T> class C >
class Map
{
    private:
        //Key<K> k;
        C<K> k;
        //Value<V> v; 
        C<V> v;
    public:
        Map();
        ~Map();
        template<typename K1, typename V1, template <typename T> class C1 >
        friend ostream& operator << (ostream&, const Map<K1, V1, C1>&);

};