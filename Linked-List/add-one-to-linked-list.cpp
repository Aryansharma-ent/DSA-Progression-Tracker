/*
 Problem: Add One to a Number Represented as Linked List

 Approach:
Use recursion to reach the end of the list and return carry. Add carry to current node and propagate back.
If a carry remains at the end, prepend a new node with value 1.

 Time Complexity: O(n)
Space Complexity: O(n) due to recursion stack
*/



#include <bits/stdc++.h>   
using namespace std; 
struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
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
class Solution {
public:
    int helper(ListNode* temp) {
        if (temp == NULL) return 1;

        int carry = helper(temp->next);
        temp->val += carry;

        if (temp->val < 10) return 0;

        temp->val = 0;
        return 1;
    }

    ListNode *addOne(ListNode *head) {
        int carry = helper(head);
        if (carry == 1) {
            ListNode* newHead = new ListNode(1);
            newHead->next = head;
            head = newHead;
        }
        return head;
    }
};
