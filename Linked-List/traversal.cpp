/*today's Progress (July 19)
✅ Topic Covered: Singly Linked List (Basics)

✅ What I Learned:

Concept of nodes (data + next pointer)

How linked list stores elements in non-contiguous memory

How to traverse and search through a singly linked list

Use of -> operator to access members of a pointer object

Understood temp = temp->next step in traversal

✅ Problems Practiced:

Print elements of a singly linked list

*/

#include<bits/stdc++.h>
using namespace std;
//Definition of singly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};
void printList(ListNode *head) {
    ListNode* temp = head;
    while(temp){
        cout << temp->val << " ";
        temp = temp->next;
    }
}
