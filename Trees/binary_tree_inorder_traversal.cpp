/*
    Problem: Binary Tree Inorder Traversal (LeetCode 94)

    Approach:
    - Use a recursive helper function to perform inorder traversal.
    - Inorder traversal follows the order: 
        1. Traverse left subtree
        2. Visit root
        3. Traverse right subtree
    - We pass the result vector by reference so all recursive calls update the same result.

    Time Complexity:
    - O(N), where N is the number of nodes in the tree.
    - Each node is visited exactly once.

    Space Complexity:
    - O(H), where H is the height of the tree (recursive stack).
    - Worst case (skewed tree): O(N).
    - Best case (balanced tree): O(log N).
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

void Recur(TreeNode* root, vector<int> &result) {
    if (root == nullptr) return;

    Recur(root->left, result);    // Traverse left
    result.push_back(root->val);  // Visit root
    Recur(root->right, result);   // Traverse right
}

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        Recur(root, ans);
        return ans;
    }
};
