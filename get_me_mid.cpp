#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

// Function to create a new node with a given value
Node* newNode(int val) {
    Node* node = new Node(val);
    node->val = val;
    node->next = NULL;
    return node;
}

// Function to insert a node at the end of the list
void List(Node** head, Node* node) {
    if (*head == NULL) {
        *head = node;
    } else {
        Node* tmp = *head;
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = node;
    }
}

// Function to sort the linked list in descending order
Node* sortList(Node* head) {
    if (!head || !head->next) return head;
    
    // Convert linked list to vector for easy sorting
    vector<int> values;
    Node* current = head;
    while (current != NULL) {
        values.push_back(current->val);
        current = current->next;
    }
    
    // Sort the vector in descending order
    sort(values.begin(), values.end(), greater<int>());
    
    // Create a new sorted linked list
    Node* sortedHead = newNode(values[0]);
    Node* sortedCurrent = sortedHead;
    for (size_t i = 1; i < values.size(); i++) {
        sortedCurrent->next = newNode(values[i]);
        sortedCurrent = sortedCurrent->next;
    }
    
    return sortedHead;
}

// Function to find and print the middle element(s) of the list
void printMiddle(Node* head) {
    if (!head) return;

    Node* slow = head;
    Node* fast = head;

    // Using the two-pointer technique to find the middle
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        if (fast != NULL) {
            slow = slow->next;
        }
    }

    // If the list has an even number of elements, print the two middle elements
    if (fast == NULL) {
        cout << slow->val << " " << slow->next->val << endl;
    } else {
        cout << slow->val << endl;
    }
}

int main() {
    Node* head = NULL;
    int val;

    // Read input until -1 is encountered
    while (cin >> val && val != -1) {
        List(&head, newNode(val));
    }

    // Sort the list in descending order
    head = sortList(head);

    // Print the middle element(s)
    printMiddle(head);

    return 0;
}
