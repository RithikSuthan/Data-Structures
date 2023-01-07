#include<iostream>
using namespace std;
struct node
{
    int data;
    node *next;
    node()
    {
        data=0;
        next=NULL;
    }
    node(int val)
    {
        data=val;
        next=NULL;
    };
    
};
class stack
{
    private:
    struct node* head;
    int top;
    public:
    stack()
    {
        head=NULL;
        top=0;
    }
    void insert(int x);
    void display();
    stack delete1(stack s1);
    void pop();
};
void stack::insert(int x)
{
    top++;
    struct  node * newnode=new node(x);
    newnode->next=head;
    head=newnode;
}
void stack::display()
{
    struct node * temp=head;
    while(temp!=NULL)
        {
            cout<<temp->data<<" => ";
            temp=temp->next;
        }
    cout<<endl;
}
stack stack::delete1(stack s1)
{
    stack s2;
    struct node * temp=s1.head;
    while(temp!=NULL)
        {
            // cout<<temp->data<<" => ";
            s2.insert(temp->data);
            temp=temp->next;
        }
        return s2;
}
void stack::pop()
{
    struct node *temp=head->next;
    free(head);
    head=temp;
}
int main()
{
    stack s1;
    stack s2;
    s1.insert(5);
    s1.insert(6);
    s1.insert(7);
    s1.insert(8);
    s1.insert(9);
    s1.display();
    s2=s2.delete1(s1);
    s2.display();
    s2.pop();
    s2.pop();
    s2.pop();
    s2.display();
    return 0;
}