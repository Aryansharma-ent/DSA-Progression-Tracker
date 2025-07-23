/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include<bits/stdc++.h>
using namespace std;


 
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    /**
     * Approach:
     * - Uses Floyd’s Cycle Detection Algorithm (Tortoise and Hare).
     * - Step 1: Use two pointers (`slow` and `fast`) to detect cycle.
     * - Step 2: If they meet, reset one pointer to head.
     * - Step 3: Move both one step at a time; the point they meet again is the start of the cycle.
     *
     * Time Complexity: O(N)
     * Space Complexity: O(1)
     */
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return NULL;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        // Step 1: Detect cycle
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                // Step 2: Find start of the cycle
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }

        return NULL; // No cycle
    }
};
