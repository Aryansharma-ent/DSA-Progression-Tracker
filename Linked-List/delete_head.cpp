
//great way to start learning linked list via these problems


#include<bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};


class Solution {
public:
    ListNode* deleteHead(ListNode* &head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
};
