/**
 * Problem: Binary Tree Preorder Traversal (Iterative Approach)
 * LeetCode: https://leetcode.com/problems/binary-tree-preorder-traversal/
 * 
 * Approach (Iterative using Stack):
 * - Use an explicit stack to simulate recursion.
 * - Push the root node into the stack.
 * - While the stack is not empty:
 *    1. Pop the top node and add its value to the preorder result.
 *    2. Push the right child (if exists) to the stack.
 *    3. Push the left child (if exists) to the stack.
 * - This ensures preorder traversal order: Root -> Left -> Right.
 * 
 * Time Complexity: O(N), where N is the number of nodes (each node visited once).
 * Space Complexity: O(N), for the stack in the worst case (skewed tree).
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        if(root == nullptr) return preorder;

        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()){
            root = st.top();
            st.pop();
            preorder.push_back(root->val);

            if(root->right != nullptr) st.push(root->right);
            if(root->left != nullptr) st.push(root->left);
        }
        return preorder;
    }
};
