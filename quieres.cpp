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

void insert_head(Node*& head, Node*& tail, int val) 
{
    Node* newNode = new Node(val);
    newNode->val = val;
    newNode->next = NULL;
    if (head == NULL) 
    {
        head = newNode;
        tail = newNode;
    }
        newNode->next = head;
        head = newNode;
}

void insert_tail(Node*& head, Node*& tail, int val) 
{
    Node* newNode = new Node(val);
    newNode->val = val;
    newNode->next = NULL;

    if (head == NULL) 
    {
        head = newNode;
        tail = newNode;
    }
    
    else 
    {
        tail->next = newNode;
        tail = newNode;
    }
}

void print_head_tail(Node* head, Node* tail) 
{
    if (head == NULL) 
    {
        return;
    }
    
    cout << head->val << " " << tail->val << endl;
}

int main() 
{
    
    Node* head = NULL;
    Node* tail = NULL;
    
    int Q;
    cin >> Q;
    
    for (int i = 0; i < Q; i++) 
    {
        int X, V;
        cin >> X >> V;
        
        if (X == 0) {
            insert_head(head, tail, V);
        }
        
        else if (X == 1) {
            insert_tail(head, tail, V);
        }
        print_head_tail(head, tail);
    }
    return 0;
}
