/**
 * Problem: Lowest Common Ancestor of a Binary Tree
 * LeetCode: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
 * 
 * Approach:
 * - Use recursion to traverse the binary tree.
 * - If the current node is NULL, return NULL.
 * - If the current node is either `p` or `q`, return the current node (potential LCA).
 * - Recursively check left and right subtrees:
 *     - If both left and right return non-NULL, current node is the LCA.
 *     - If only one side returns non-NULL, propagate that result upwards.
 * 
 * Why it works:
 * - The recursion unwinds only when both `p` and `q` are found.
 * - The node where paths from `p` and `q` meet for the first time is the LCA.
 * 
 * Time Complexity: O(N)
 *   - Each node is visited once, so linear in the number of nodes.
 * 
 * Space Complexity: O(H)
 *   - Due to recursion stack, where H = height of tree.
 *   - Worst case: skewed tree → O(N), best case balanced tree → O(log N).
 * 
 */

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base cases: root is null or matches p or q
        if (root == nullptr || root == p || root == q) {
            return root;
        }

        // Search left and right subtrees
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // If both non-null, current node is LCA
        if (left != NULL && right != NULL) {
            return root;
        }

        // Otherwise propagate non-null child upwards
        return (left != NULL) ? left : right;
    }
};
