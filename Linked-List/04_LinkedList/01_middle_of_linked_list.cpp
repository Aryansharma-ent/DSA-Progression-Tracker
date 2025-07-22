/**
 * LeetCode Problem: Middle of the Linked List
 * Link: https://leetcode.com/problems/middle-of-the-linked-list/
 *
 * Approach: Fast and Slow Pointer (Tortoise Method)
 * -----------------------------------------------
 * We initialize two pointers:
 * - slow -> moves one step at a time
 * - fast -> moves two steps at a time
 *
 * When 'fast' reaches the end of the list,
 * 'slow' will be at the middle node.
 *
 * Time Complexity: O(N) -> We traverse the list once
 * Space Complexity: O(1) -> No extra space is used
 *
 * Returns the middle node of the linked list.
 * If there are two middle nodes, return the second one.
 */

//  * Definition for singly-linked list.

#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
        // Move slow by 1
    }
};
