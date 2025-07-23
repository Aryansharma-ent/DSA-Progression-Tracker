// ✅ Palindrome Linked List
// Approach: 
// 1. Find the middle using slow & fast pointer.
// 2. Reverse the second half of the list.
// 3. Compare both halves.
// 4. Restore the list to original state (reverse again).
// Time Complexity: O(n)
// Space Complexity: O(1) (excluding recursion stack for reversal)

#include <bits/stdc++.h>
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
    ListNode* ReverseLinkedList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        ListNode* newHead = ReverseLinkedList(head->next);
        head->next->next = head;
        head->next = NULL;

        return newHead;
    }

    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;

        // Step 1: Find the middle
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse second half
        ListNode* newHead = ReverseLinkedList(slow->next);

        // Step 3: Compare both halves
        ListNode* first = head;
        ListNode* second = newHead;
        while(second) {
            if(first->val != second->val) {
                ReverseLinkedList(newHead); // Restore list important for interviews
                return false;
            }
            first = first->next;
            second = second->next;
        }

        // Step 4: Restore the list again if true
        ReverseLinkedList(newHead);
        return true;
    }
};
