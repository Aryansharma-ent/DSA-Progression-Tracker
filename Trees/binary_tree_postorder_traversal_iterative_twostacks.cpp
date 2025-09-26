/**
 * Problem: Binary Tree Postorder Traversal (Iterative Approach using Two Stacks)
 * LeetCode: https://leetcode.com/problems/binary-tree-postorder-traversal/
 * 
 * Approach (Iterative using Two Stacks):
 * - Use two stacks to simulate recursion for postorder (Left -> Right -> Root).
 * - Push the root into the first stack (st1).
 * - While st1 is not empty:
 *    1. Pop from st1 and push it into st2.
 *    2. Push its left child into st1 (if exists).
 *    3. Push its right child into st1 (if exists).
 * - After this, st2 will contain nodes in Root -> Right -> Left order.
 * - Pop everything from st2 to get Left -> Right -> Root (postorder).
 * 
 * Time Complexity: O(N), where N is the number of nodes (each node visited once).
 * Space Complexity: O(N), for the two stacks in the worst case (skewed tree).
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        if(root == nullptr) return postorder;

        stack<TreeNode*> st1, st2;
        st1.push(root);

        while(!st1.empty()){
            TreeNode* node = st1.top();
            st1.pop();
            st2.push(node);

            if(node->left != nullptr) st1.push(node->left);
            if(node->right != nullptr) st1.push(node->right);
        }

        while(!st2.empty()){
            postorder.push_back(st2.top()->val);
            st2.pop();
        }

        return postorder;
    }
};
