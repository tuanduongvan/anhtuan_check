#include "stack.h"

stack::stack(int a)
    :maxsize(a)
{ 
    this->top = NULL;
    this->size = 0;
}

stack::~stack()
{
    while(!isEmpty())
    {
        Pop();
    }
}
//kiem tra ngan xep rong
bool stack::isEmpty()
{
    return (this->size == 0) ? true : false;
}

//kiem tra
bool stack::isFull()
{
    return this->size == maxsize;
}
//dua mot phan tu vao dinh ngan xep
void stack::Push(int x)
{
    if (isFull())
        cout <<"ngan xep da day!!" << endl;
    else
    {
        Node* newnode = new Node(x);
        if (this->isEmpty())
            this->top = newnode;
        else 
            newnode->next = this->top;
            this->top = newnode;
        this->size++;
    }
}
//lay phan tu dinh cua ngan xep
int stack::Pop()
{
    if(isEmpty())
        return -1;
    int dem = top->value;
    Node* temp = top;
    top = top->next;
    //delete temp;
    size--;
    return dem;
}
//so phan tu hien tai trong ngan xep
int stack::numberofelement()
{
    return this->size;
}

void stack::Print()
{
    Node* temp = this->top;
    while (temp != NULL)
    {
        cout << temp->id << ": ";
        cout << temp->value << endl;
        temp = temp->next;
    }

}
//ham dung sao chep
stack::stack(const stack& st)
    :maxsize(st.maxsize)
{
    Node* otherTop = st.top;
    Node* newTop = nullptr;
    while (otherTop != nullptr) {
        Node* newNode = new Node(otherTop->value);
        if (newTop == nullptr) {
            top = newNode;
        } else {
            newTop->next = newNode;
        }
        newTop = newNode;
        otherTop = otherTop->next;
        size++;
    }
}
