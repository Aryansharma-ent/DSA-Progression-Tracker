/*
Problem: Delete the head node from a doubly linked list.

Approach:
- If the list is empty or has only one node, return NULL.
- Store the original head in a temp pointer.
- Move head to the next node.
- Set previous of new head to NULL and remove next of the old head.
- Delete the old head to free memory.

Time Complexity: O(1)
Space Complexity: O(1)
*/

#include<bits/stdc++.h>
using namespace std;

// Definition of doubly linked list:
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
    ListNode * deleteHead(ListNode* head) {

        if(head == NULL || head->next == NULL){
            return NULL;
        }
ListNode* piche = head;
head = head->next;
piche->next = NULL;
head->prev = NULL;
delete piche;
return head;
    }
};