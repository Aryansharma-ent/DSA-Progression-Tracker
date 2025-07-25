/* We are given a singly linked list containing only 0s, 1s, and 2s. The goal is to sort it in a single traversal without changing node data — only rearranging pointers

We use 3 dummy nodes to separate nodes of value 0, 1, and 2 respectively.
We iterate through the list once and attach each node to its corresponding list based on value.
Then we connect all three sublists (0s → 1s → 2s) and return the head of the sorted list.

This avoids swapping values and makes the code pointer-based and efficient.

Time Complexity:
O(N) — We iterate the list only once.

 Space Complexity:
O(1) — Only extra pointers used; no new nodes are created (besides dummies).
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
    ListNode *sortList(ListNode *head) {
        ListNode* zerohead = new ListNode(-1);
        ListNode* onehead = new ListNode(-1);
        ListNode* twohead = new ListNode(-1);

        ListNode* zero = zerohead;
        ListNode* one = onehead;
        ListNode* two = twohead;

        ListNode* temp = head;

        while(temp != NULL) {
            if(temp->val == 0){
                zero->next = temp;
                zero = temp;
            } else if(temp->val == 1){
                one->next = temp;
                one = temp;
            } else {
                two->next = temp;
                two = temp;
            }
            temp = temp->next;
        }

        zero->next = (onehead->next) ? onehead->next : twohead->next;
        one->next = twohead->next;
        two->next = NULL;

        return zerohead->next;
    }
};
