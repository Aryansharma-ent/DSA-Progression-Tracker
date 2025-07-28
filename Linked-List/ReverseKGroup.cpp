// File: ReverseKGroup.cpp

/*
Approach:
We iterate through the linked list in chunks of size k. For each chunk:
1. We check if there are at least k nodes available using FindKth.
2. If yes, we temporarily detach the chunk, reverse it using ReverseLL(),
   then connect it back to the previous chunk.
3. We keep track of the tail of the last processed chunk (prevLast).
4. If remaining nodes < k, we leave them as-is.

Time Complexity: O(n)
- Every node is visited and reversed at most once.

Space Complexity: O(1)
- Only constant extra space is used (no recursion or extra list).

*/

#include <iostream>
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
    // Reverses a linked list and returns the new head
    ListNode* ReverseLL(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;

        while (curr != NULL) {
            ListNode* NextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = NextNode;
        }

        return prev; // New head after reversal
    }

    // Finds the kth node from the current node
    ListNode* FindKth(ListNode* temp, int k) {
        k -= 1;
        while (temp != NULL && k > 0) {
            k--;
            temp = temp->next;
        }
        return temp;
    }

    // Main function to reverse nodes in k-group
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevLast = NULL;
        ListNode* newHead = NULL;

        while (temp != NULL) {
            // Find the kth node
            ListNode* KthNode = FindKth(temp, k);
            if (KthNode == NULL) {
                if (prevLast) {
                    prevLast->next = temp;
                }
                break;
            }

            ListNode* nextnode = KthNode->next;
            KthNode->next = NULL;

            // Reverse current k-group
            ListNode* reversedHead = ReverseLL(temp);

            // Update new head if first group
            if (newHead == NULL) {
                newHead = reversedHead;
            }

            // Connect last part to reversed head
            if (prevLast != NULL) {
                prevLast->next = reversedHead;
            }

            // Update prevLast and temp
            prevLast = temp;
            temp = nextnode;
        }

        return newHead != NULL ? newHead : head;
    }
};
