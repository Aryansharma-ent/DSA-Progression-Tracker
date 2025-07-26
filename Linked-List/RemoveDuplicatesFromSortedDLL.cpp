/*
GFG question: https://practice.geeksforgeeks.org/problems/remove-duplicates-from-sorted-doubly-linked-list/1
Approach:
Since the list is sorted, duplicates are adjacent.

Use two pointers:

temp1 → points to the current distinct node.

temp2 → scans ahead to find the next non-duplicate node.

If temp2->data == temp1->data, move temp2 forward (skip duplicate).

Else, link temp1->next = temp2, and temp2->prev = temp1, then advance both.

At the end, ensure temp1->next = NULL to properly terminate the list.

 Time & Space Complexity:
Time Complexity: O(N) — where N is the number of nodes.

Space Complexity: O(1) — in-place pointer manipulation.

*/

#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }

};
class Solution {
  public:
    Node *removeDuplicates(struct Node *head) {
        Node* temp1 = head;
        Node* temp2 = head->next;

        while (temp2 != NULL) {
            if (temp1->data == temp2->data) {
                temp2 = temp2->next;
            } else {
                temp1->next = temp2;
                temp2->prev = temp1;
                temp1 = temp2;
                temp2 = temp2->next;
            }
        }

        temp1->next = NULL; // Important: cut off any leftover duplicates
        return head;
    }
};
