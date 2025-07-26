/* Problem: Add One to a Number Represented as Linked List
 Approach:
 We recursively traverse to the end of the linked list and start returning carry from the last node.
 Each node adds the carry to its value.
 If the value becomes 10, we set it to 0 and return a carry of 1 to the previous node.
 If the value is less than 10, we just return carry 0.
 Finally, if there's still a carry left after processing the head node, we create a new node with value 1 and make it the new head.

 Edge Case:
 For a list like 9 → 9 → 9, the result becomes 1 → 0 → 0 → 0.

 Time Complexity: O(n) — we visit each node once via recursion.
 Space Complexity: O(n) — due to recursive call stack.*/



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
