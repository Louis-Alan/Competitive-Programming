#include <bits/stdc++.h>
using namespace std;

class node
{
    public:
    int data;
    node* next;

    node(int val)
    {
        data = val;
        next = nullptr;
    }
};

void insertTail(node* &head, int val)
{
    node* n = new node(val);
    if(head == nullptr)
    {
        head = n;
        return;
    }

    node* temp = head;
    while(temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = n;
}

void insertAfter(node* head, int key, int val)
{
    node* n = new node(val);
    if(key == head->data)
    {
        n->next = head->next;
        head->next = n;
        return;
    }

    node* temp = head;
    while(temp->data != key)
    {
        temp = temp->next;
    }
    n->next = temp->next;
    temp->next = n;
}

void insertHead(node* head, int val)
{
    node* n = new node(val);
    if(head == nullptr)
    {
        head = n;
        return;
    }
    n->next = head;
    head = n;
}

void printt(node* head)
{
    node* temp = head;
    while(temp != nullptr)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main()
{
    char c = 'y';
    int n, val;
    node* head = nullptr;
    while(c == 'y' || c == 'Y')
    {
        cout<<"1. Insert at Head\n";
        cout<<"2. Insert at Tail\n";
        cout<<"3. Insert after element\n";
        cout<<"4. Print\n";
        cout<<"Enter Choice: ";
        cin>>n;
        switch(n)
        {
            case 1: cout<<"Enter val: ";
                    cin>>val;
                    insertHead(head, val);
                    break;
            case 2: cout<<"Enter val: ";
                    cin>>val;
                    insertTail(head, val);
                    break;
            case 3: cout<<"Enter val: ";
                    cin>>val;
                    cout<<"Enter val to be inserted after: ";
                    int key;
                    cin>>key;
                    insertAfter(head, key, val);
                    break;
            case 4: cout<<"Linked list is\n";
                    printt(head);
                    break;
            default:cout<<"wrong input";
        }
        cout<<"\n\nDo u want to continue operations(y or n): ";
        cin>>c;
    }
    return 0;
}