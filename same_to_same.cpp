// A node of a singly linked list
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

// A function to create a new node with a given value
Node* newNode(int val) 
{
  Node* node = new Node(val); 
  node->val = val; 
  node->next = NULL;
  return node;
}


void List(Node** head, Node* node) 
{
  if (*head == NULL) 
  {
    *head = node;
  } 
  else 
  { 
    Node* tmp = *head; 
    while (tmp->next != NULL) 
    { 
      tmp = tmp->next;
    }
    tmp->next = node;
  }
}

bool same(Node* head1, Node* head2) 
{
  Node* tmp1 = head1; 
  Node* tmp2 = head2; 
  while (tmp1 != NULL && tmp2 != NULL) 
  { 
    if (tmp1->val != tmp2->val) 
    {
      return false;
    }
    tmp1 = tmp1->next; 
    tmp2 = tmp2->next; 
  }
  if (tmp1 == NULL && tmp2 == NULL) 
  { 
    return true;
  } 
  else 
  { 
    return false;
  }
}


int main() {
  Node* head1 = NULL; 
  Node* head2 = NULL; 

  int val;
  while (cin >> val && val != -1) 
  {
    List(&head1, newNode(val));
  }

  while (cin >> val && val != -1) 
  {
    List(&head2, newNode(val)); 
  }

  if (same(head1, head2)) 
  {
    cout << "YES" << endl;
  } 
  else 
  {
    cout << "NO" << endl;
  }

  return 0;
}