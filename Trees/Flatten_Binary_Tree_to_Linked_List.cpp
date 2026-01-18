/*
Problem: Flatten Binary Tree to Linked List
Platform: LeetCode
Problem No: 114

Problem Statement:
Given the root of a binary tree, flatten the tree into a "linked list" in-place.
The linked list should follow the same order as a pre-order traversal:
root -> left -> right

After flattening:
- Each node's right pointer points to the next node in the list.
- Each node's left pointer must be NULL.

Approach:
- Use reverse preorder traversal (right -> left -> root).
- Maintain a pointer `prev` which stores the previously processed node.
- While backtracking:
  - Set root->right = prev
  - Set root->left = nullptr
  - Update prev = root

Why this works:
- Reverse preorder ensures that when processing a node, `prev` already points to
  the correct next node in the flattened linked list.
- This allows flattening in-place without extra arrays.

Time Complexity:
- O(N), where N is the number of nodes (each visited once).

Space Complexity:
- O(H), recursion stack where H is the height of the tree.
  Worst case O(N) for a skewed tree.
*/

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* prev = nullptr;

    void flatten(TreeNode* root) {
        if (!root) return;

        flatten(root->right);
        flatten(root->left);

        root->right = prev;
        root->left = nullptr;
        prev = root;
    }
};
