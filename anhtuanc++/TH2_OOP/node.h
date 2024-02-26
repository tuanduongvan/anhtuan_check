#include <iostream>

using namespace std;

class Node
{
    int value;
    Node* next;
    int id;
    public:
        Node(int);
        Node(const Node&);
        void nhap();
        friend class stack; 
};