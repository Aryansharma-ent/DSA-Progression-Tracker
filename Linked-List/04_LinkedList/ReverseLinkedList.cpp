/**
 * Problem: Reverse a Singly Linked List
 * Leetcode: https://leetcode.com/problems/reverse-linked-list/
 * 
 * Approaches:
 * 1. Iterative Approach using 3 pointers (prev, curr, next)
 * 2. Recursive Approach
 * 
 * Time Complexity: O(N) for both approaches
 * Space Complexity:
 *     - Iterative: O(1)
 *     - Recursive: O(N) due to recursion stack
 */

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

    // Iterative Approach
    ListNode* reverseListIterative(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while(curr != nullptr) {
            ListNode* nextNode = curr->next; 
            curr->next = prev;               
            prev = curr;                     
                      curr = nextNode;                 
        }
        return prev;
    }

    //  Recursive Approach
    ListNode* reverseListRecursive(ListNode* head) {
        // base case: empty list or single node
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* newHead = reverseListRecursive(head->next); // reverse rest
        head->next->next = head; // make next node point to current
        head->next = nullptr;    // set current's next to null
        return newHead;
    }
};
