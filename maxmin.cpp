#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
        int val;
        Node* next;
    Node(int val)
    {
        this->val=val;
        this->next=NULL;
    }
};

void insert_tail(Node *&head, Node *&tail, int val)
{
    Node* newNode = new Node(val);
    if(head==NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

int maximum(Node* head)
{
    int max = INT_MIN;
    Node *tmp = head;
    while(tmp != NULL)
    {
        if(max < tmp->val)
        {
            max = tmp->val;
        }
        tmp = tmp->next;
    }
    return max;
}

int minimum(Node* head)
{
    int min = INT_MAX;
    Node *tmp = head;
    while(tmp != NULL)
    {
        if(min > tmp->val)
        {
            min = tmp->val;
        }
        tmp = tmp->next;
    }
    return min;
}
int main()
{
    Node* head = NULL;
    Node* tail = NULL;
    int val;
    while(true)
    {
        cin>>val;
        if(val==-1) break;
        insert_tail(head,tail,val);
    }
    
    cout<< maximum(head) << " " << minimum(head) << endl; 
    return 0;
}