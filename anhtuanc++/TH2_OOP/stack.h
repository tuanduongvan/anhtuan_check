#include <iostream>
#include "node.h"
using namespace std;

class stack
{
    private:
        const int maxsize;
        Node* top;
        int size;
    public:
        stack(int);
        ~stack();
        void Push(int);//da du lieu vao dau ngan xep
        int Pop();//xoa di phan tu dau tien
        bool isEmpty();//ngan xeo rong
        int numberofelement();//dem so phan tu trong ngan xep
        void Print();//in ra cac phan tu cua stack
        //bai 2
        bool isFull();
        stack(const stack&);
};