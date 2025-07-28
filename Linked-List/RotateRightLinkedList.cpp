// File: RotateRightLinkedList.cpp

/*
Approach:
1. First, calculate the length of the list and locate the tail.
2. Connect the tail to the head to make the list circular.
3. Find the new last node, which is (length - k % length) steps from the head.
4. The new head is the next of this new last node.
5. Break the circular link by setting newLast->next = NULL.
6. Return the new head.

Edge cases are handled, such as when k == 0 or list size == 1.

Time Complexity: O(n)
- One pass to find length and another to locate the new tail.

Space Complexity: O(1)
- Only constant space used.
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
    // Utility to get the (k-1)th node from a given node
    ListNode* findnewlasth(ListNode* temp, int k){
        while(k > 1){
            k--;
            temp = temp->next;
        }
        return temp;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        // Find length and tail of list
        ListNode* tail = head;
        int len = 1;
        while (tail->next != NULL) {
            len++;
            tail = tail->next;
        }

        // Optimize k to ensure ease of roatation with small k values
        k = k % len;
        if (k == 0) return head;

        // Make it circular
        tail->next = head;

        // Find new tail: (len - k)th node
        ListNode* NewLasthead = findnewlasth(head, len - k);

        // Set new head
        head = NewLasthead->next;

        // Break the loop
        NewLasthead->next = NULL;

        return head;
    }
};
