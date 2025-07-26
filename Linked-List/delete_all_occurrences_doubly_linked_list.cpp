/*
Problem:
Given a doubly linked list and an integer target, delete all nodes in the list that have value equal to target.

Approach:
- Traverse the list from head to end.
- For each node, check if its value equals the target.
- If it does:
    - If it has a previous node, rewire the previous node’s next pointer to skip current.
    - If it’s the head node, update the head to the next node.
    - If it has a next node, rewire the next node’s prev pointer.
    - Delete the node from memory safely.
- Move to the next node and repeat.

This ensures all occurrences of target are removed, and the doubly linked list remains correctly linked.

Time Complexity: O(N)
- We visit each node once.

Space Complexity: O(1)
- No extra space used except pointers.
*/

#include<bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode()
    {
        val = 0;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode *prev1)
    {
        val = data1;
        next = next1;
        prev = prev1;
    }
};


class Solution {
public:
    ListNode* deleteAllOccurrences(ListNode* head, int target) {
        ListNode* temp = head;

        while (temp != NULL) {
            if (temp->val == target) {
                ListNode* toDelete = temp;

                
                temp = temp->next;

     
                if (toDelete->prev != NULL) {
                    toDelete->prev->next = toDelete->next;
                } else {
               
                    head = toDelete->next;
                }

       
                if (toDelete->next != NULL) {
                    toDelete->next->prev = toDelete->prev;
                }

              
                toDelete->next = NULL;
                toDelete->prev = NULL;
                delete toDelete;
            } else {
                
                temp = temp->next;
            }
        }

        return head;
    }
};
