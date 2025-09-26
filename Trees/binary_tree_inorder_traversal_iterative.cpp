/**
 * Problem: Binary Tree Inorder Traversal (Iterative Approach)
 * LeetCode: https://leetcode.com/problems/binary-tree-inorder-traversal/
 * 
 * Approach (Iterative using Stack):
 * - Use an explicit stack to simulate recursion for inorder (Left -> Root -> Right).
 * - Start from the root and keep going left while pushing nodes into the stack.
 * - When reaching a null, pop from the stack, process the node, and move to its right child.
 * - Repeat until both the stack is empty and the current node is null.
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        if(root == nullptr) return inorder;

        stack<TreeNode*> st;
        TreeNode* node = root;

        while(true){
            if(node != nullptr){
                st.push(node);
                node = node->left;
            } else {
                if(st.empty()) break;
                node = st.top();
                st.pop();
                inorder.push_back(node->val);
                node = node->right;
            }
        }
        return inorder;
    }
};
