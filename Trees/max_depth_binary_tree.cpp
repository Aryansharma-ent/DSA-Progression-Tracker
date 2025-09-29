/*
    Problem: Maximum Depth of Binary Tree
    -------------------------------------
    Approach:
    - We use recursion (Depth-First Search).
    - For each node, compute the depth of its left subtree and right subtree.
    - The maximum depth at the current node = 1 + max(leftDepth, rightDepth).
    - Base case: if node is NULL, return 0.

    Time Complexity:
    - O(N), where N = number of nodes in the tree.
      (We visit each node once.)

    Space Complexity:
    - O(H), where H = height of the tree (recursive stack).
      Worst case: O(N) for a skewed tree, O(log N) for a balanced tree.
*/

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);
        return 1 + max(lh, rh);
    }
};
