
// Description: Implementations of insertions in a singly linked list.
// Operations Covered:
//     1. Insert at Head
//     2. Insert at Tail
//     3. Insert at Kth Position
//  Time Complexity:
//     - Insert at Head: O(1)
//     - Insert at Tail: O(n) (can be O(1) if tail pointer is maintained)
//     - Insert at Kth Position: O(k)

#include <iostream>
using namespace std;

//  Definition for singly-linked list node
struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

//  Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// 🔨 Insert at Head
void insertAtHead(Node*& head, int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

//  Insert at Tail
void insertAtTail(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

//  Insert at Kth Position (1-based indexing)
void insertAtK(Node*& head, int k, int val) {
    if (k == 1) {
        insertAtHead(head, val);
        return;
    }
    Node* temp = head;
    int count = 1;
    while (temp != nullptr && count < k - 1) {
        temp = temp->next;
        count++;
    }
    if (temp == nullptr) {
        cout << " Invalid Position!\n";
        return;
    }
    Node* newNode = new Node(val);
    newNode->next = temp->next;
    temp->next = newNode;
}


