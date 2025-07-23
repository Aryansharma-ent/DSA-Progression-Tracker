/**
 * LeetCode: Odd Even Linked List
 * Difficulty: Medium
 * 
 * Approach:
 * - Use two pointers: one for odd-indexed nodes and one for even-indexed nodes.
 * - Keep track of the starting node of even-indexed list (evenHead).
 * - Traverse the list and rearrange odd and even nodes separately.
 * - Finally, connect the odd list with the even list.
 * 
 * Time Complexity: O(n)
 * - We iterate over the list once, processing each node only once.
 * 
 * Space Complexity: O(1)
 * - Rearranging is done in-place without using extra space.
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
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head; // Already odd-even arranged if ≤1 node
        }

        // Separate pointers for odd and even indexed nodes
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even; // Save head of even list for later stitching

        // Traverse and rearrange nodes
        while (even != NULL && even->next != NULL) {
            odd->next = odd->next->next;
            even->next = even->next->next;

            odd = odd->next;
            even = even->next;
        }

        // Attach even list at end of odd list (important step cause i almost forgot to that)
        odd->next = evenHead;
        return head;
    }
};
