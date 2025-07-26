/*
GFG question: https://practice.geeksforgeeks.org/problems/find-pairs-with-given-sum-in-doubly-linked-list/1
Approach:
- This is a classic two-pointer problem applied on a **sorted doubly linked list**.
- We initialize two pointers: 
  - `left` at the head of the list.
  - `right` at the tail (by traversing to the end).
- We iterate while `left` is before `right`.
  - If the sum of `left->data + right->data` equals target → store the pair and move both pointers.
  - If sum is less than target → move `left` forward to increase sum.
  - If sum is more than target → move `right` backward to decrease sum.
- Continue until the two pointers meet or cross.


Time Complexity: O(N)
- We traverse the list once to get the tail (O(N)), and then use the two-pointer approach which also takes O(N) in total.

Space Complexity: O(1) (excluding output space)
- No extra data structures used apart from output.


*/

#include<bits/stdc++.h>
using namespace std;




class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};


class Solution {
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node* head, int target) {
      
        vector<pair<int, int>> ans;

     
        if (!head || !head->next) return ans;

        Node* left = head;
        Node* right = head;

    
        while (right->next != NULL) {
            right = right->next;
        }

        // Two-pointer approach
        while (left != NULL && right != NULL && left != right && left->prev != right) {
            int sum = left->data + right->data;

            if (sum > target) {
                right = right->prev;  
            }
            else if (sum < target) {
                left = left->next;    
            }
            else {
                
                ans.push_back({left->data, right->data});
                left = left->next;
                right = right->prev;
            }
        }

        return ans;
    }
};
