/**
 
 /**
  * Leetcode Problem: Remove Nth Node From End of List
  * 
  * Approach:
  * - First, count the total number of nodes in the linked list.
  * - If n == count, that means we have to remove the head node, so return head->next.
  * - Otherwise, traverse again to the (count - n - 1)th node.
  * - Change its next pointer to skip the nth node from the end.
  * 
  * Time Complexity: O(n)
  * Space Complexity: O(1)
  */
//   Definition for singly-linked list.

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        if (head == NULL || head->next == NULL) {
            return NULL;
        }

        int count = 0;
        ListNode* temp = head;

        while (temp != NULL) {
            count++;
            temp = temp->next;
        }

        // Edge case: remove the first node
        if (count == n) {
            return head->next;
        }

        temp = head;
        for (int i = 1; i < count - n; i++) {
            temp = temp->next;
        }

        temp->next = temp->next->next;

        return head;
    }
};
