/*
    Problem: Balanced Binary Tree
    ------------------------------
    Approach:
    - We use recursion to calculate both height and balance in one pass.
    - For each node:
        1. Compute left and right subtree heights.
        2. If either subtree is unbalanced (returns -1), propagate -1 upward.
        3. If the height difference exceeds 1, mark as unbalanced (-1).
        4. Otherwise, return 1 + max(leftHeight, rightHeight).
    - Final check: if the root returns -1, the tree is not balanced.

    Optimized Trick:
    - Instead of recalculating subtree heights separately (O(N^2)), 
      we merge balance-check + height computation in a single recursion.

    Time Complexity:
    - O(N), where N = number of nodes in the tree (each node visited once).

    Space Complexity:
    - O(H), where H = height of the tree (recursive stack).
      Worst case: O(N) for skewed tree, O(log N) for balanced tree.
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
    int Recur(TreeNode* root) {
        if(root == nullptr) return 0;

        int lh = Recur(root->left);
        int rh = Recur(root->right);

        if(lh == -1 || rh == -1) return -1;   // subtree unbalanced
        if(abs(lh - rh) > 1) return -1;       // current node unbalanced

        return 1 + max(lh, rh);               // return height if balanced
    }

    bool isBalanced(TreeNode* root) {
        return Recur(root) != -1;
    }
};
