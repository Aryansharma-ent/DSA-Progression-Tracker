/**
  Problem: Delete the Middle Node of a Linked List
  Leetcode: https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
  
  Approach:
  - Use the slow and fast pointer technique to find the middle of the list.
  - Track the previous node of slow using a `prev` pointer.
  - When the fast pointer reaches the end, the slow pointer is at the middle node.
  - Remove the middle node by updating `prev->next`.
  
  Edge Case:
  - If the list has only one node, delete it and return NULL.
  
  Time Complexity: O(n) — where n is the number of nodes (single pass to find middle).
  Space Complexity: O(1) — constant extra space used.
 */

#include<bits/stdc++.h>
using namespace std;
  
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return NULL;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }

        prev->next = prev->next->next;
        delete slow;
        return head;
    }
};
