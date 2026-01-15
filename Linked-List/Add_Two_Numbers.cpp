/*
Problem: Add Two Numbers
Platform: LeetCode
Problem No: 2

Problem Statement:
You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order, and each of their nodes contains a single digit.
Add the two numbers and return the sum as a linked list.

Assume the two numbers do not contain any leading zero, except the number 0 itself.

Approach:
- Use a dummy node to simplify linked list construction.
- Traverse both linked lists simultaneously.
- Maintain a carry for sums greater than 9.
- At each step:
  - Add corresponding digits from both lists and the carry.
  - Create a new node with (sum % 10).
  - Update carry as (sum / 10).
- Continue until both lists are exhausted and carry becomes zero.

Why this works:
- Since digits are stored in reverse order, addition can be performed directly
  from head to tail, just like manual addition.
- Dummy node avoids special handling for the head of the result list.

Time Complexity:
- O(max(m, n)), where m and n are the lengths of the two linked lists.

Space Complexity:
- O(max(m, n)), for the output linked list.
*/

#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        int carry = 0;

        while (l1 || l2 || carry) {
            int sum = carry;

            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            tail->next = new ListNode(sum % 10);
            tail = tail->next;
        }

        return dummy.next;
    }
};
