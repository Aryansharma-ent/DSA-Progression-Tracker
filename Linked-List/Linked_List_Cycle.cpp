/*
Approach: Floyd’s Cycle Detection Algorithm (Tortoise and Hare)
---------------------------------------------------------------
We use two pointers: slow and fast. Slow moves one step at a time,
fast moves two steps at a time. If there's a cycle, they will eventually
meet inside the loop. If there's no cycle, fast will reach the end.

Time Complexity: O(N)
Space Complexity: O(1)
*/

//   Definition for singly-linked list.
#include<bits/stdc++.h>
using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL){
            return false;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                return true; // Cycle detected
            }
        }

        return false; // No cycle
    }
};
