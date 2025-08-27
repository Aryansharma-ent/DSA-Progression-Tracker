/*
    Problem: Merge K Sorted Linked Lists

    Approach:
    - Use a min-heap (priority_queue) to always know the smallest current node among all lists.
    - Push the head of each non-empty list into the heap.
    - While the heap is not empty:
        - Pop the smallest node from the heap and append it to the merged list.
        - If the popped node has a next node, push it into the heap.
    - Continue until all nodes are processed.

    Example:
    lists = [
        1 -> 4 -> 5,
        1 -> 3 -> 4,
        2 -> 6
    ]
    Merged List = 1 -> 1 -> 2 -> 3 -> 4 -> 4 -> 5 -> 6

    Time Complexity: O(N log k)
        - N = total nodes across all lists
        - Each push/pop operation on heap of size <= k takes O(log k)

    Space Complexity: O(k)
        - Heap stores at most one node per list at any time

    DSA Sheet Position: Heaps → Applications → Merge K Sorted Lists
*/

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    struct Compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val; // min-heap
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> mh;

        // Push the head of each non-empty list
        for(int i = 0; i < lists.size(); i++){
            if(lists[i] != nullptr){
                mh.push(lists[i]);
            }
        }

        ListNode* ans = new ListNode(-1); // dummy node
        ListNode* temp = ans;

        // Process heap
        while(!mh.empty()){
            ListNode* list = mh.top();
            mh.pop();
            temp->next = list;
            temp = temp->next;

            // Push next node from same list into heap if exists
            if(list->next != nullptr){
                mh.push(list->next);
            }
        }

        return ans->next; // skip dummy node
    }
};
