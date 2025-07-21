/*
Problem: Reverse a doubly linked list.

Approach:
- Traverse through the list and swap `next` and `prev` pointers for each node.
- After the loop, `last->prev` gives the new head.

Time Complexity: O(n)
Space Complexity: O(1)
*/


#include<bits/stdc++.h>
using namespace std;
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
    ListNode* reverseDLL(ListNode* head) {
        ListNode* last = NULL;
        ListNode* current = head;

        if (head == NULL || head->next == NULL) {
            return head;
        }

        while (current != NULL) {
            last = current->prev;
            current->prev = current->next;
            current->next = last;
            current = current->prev;
        }

        return last->prev;
    }
};
