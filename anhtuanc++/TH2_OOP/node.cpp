#include "node.h"

Node::Node(int n)
{
    this->value = n;
    this->next = NULL;
    static int nextid = 1;
    this->id = nextid++;
}

void Node::nhap()
{
    cout << "nhap gia tri cho node: ";
    cin >> this->value;
}
//bai 2
Node::Node(const Node& n)
{
    this->id = n.id;
    this->next = n.next;
    this->value = n.value;
}