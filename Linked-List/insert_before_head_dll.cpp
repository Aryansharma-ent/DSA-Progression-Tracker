/*
Problem: Insert a node before the current head in a doubly linked list.

Approach:
- Allocate memory for a new node with given value `X`.
- Point its `next` to the current head and `prev` to NULL.
- Update the previous pointer of the original head to this new node.
- Return the new node as the updated head.

Time Complexity: O(1)
Space Complexity: O(1)
*/
#include<bits/stdc++.h>
using namespace std;
// Definition of doubly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode()
    {
        val = 0;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode *prev1)
    {
        val = data1;
        next = next1;
        prev = prev1;
    }
};


class Solution {
public:
    ListNode* insertBeforeHead(ListNode* head, int X) {
        ListNode* temp = new ListNode(X, head, NULL);
        if (head != NULL) head->prev = temp;
        return temp;
    }
};

