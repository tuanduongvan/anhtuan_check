#include "stack.h"

int main()
{
    stack st(3);
    st.Push(2);
    st.Push(3);
    st.Push(5);
    st.Push(6);
    //su dung ham dung sao chep
    stack st1 (st);

    cout << "so phan tu hien co trong ngan xep: ";
    int a = st.numberofelement();
    cout << a << endl;

    int x = st.Pop();
    cout << "phan tu duoc rut ra: ";
    cout << x << endl;

    cout << "so phan tu hien co trong ngan xep: ";
    int b = st.numberofelement();
    cout << b << endl;

    int c = st.Pop();
    cout << "phan tu duoc rut ra: ";
    cout << c << endl;
    st.Print();
    cout << "=======" << endl;
    st1.Print();

    return 0;
}