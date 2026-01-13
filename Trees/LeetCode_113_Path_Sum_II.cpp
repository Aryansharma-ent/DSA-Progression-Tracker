/*
Problem: Path Sum II
Platform: LeetCode
Problem No: 113

Problem Statement:
Given the root of a binary tree and an integer targetSum, return all root-to-leaf
paths where the sum of the node values in each path equals targetSum.

Each path must start at the root and end at a leaf node.

Approach:
- Use Depth First Search (DFS) with backtracking.
- Maintain a temporary vector to store the current path.
- Subtract the current node's value from targetSum as we move down.
- When a leaf node is reached:
  - If the remaining targetSum equals the leaf value, store the current path.
- Backtrack by removing the current node before returning to the parent.

Why this works:
- DFS explores all root-to-leaf paths.
- Backtracking ensures paths are built correctly without interference.
- Only valid paths with exact sum are collected.

Time Complexity:
- O(N), where N is the number of nodes in the tree.
- Each node is visited once.

Space Complexity:
- O(H), where H is the height of the tree (recursion stack).
- Additional space is used to store valid paths.
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
    void Recur(vector<vector<int>>& ans,
               vector<int>& temp,
               TreeNode* root,
               int targetSum) {

        if (root == nullptr) return;

        temp.push_back(root->val);

        // If leaf node, check remaining sum
        if (root->left == nullptr && root->right == nullptr) {
            if (targetSum == root->val) {
                ans.push_back(temp);
            }
        } else {
            Recur(ans, temp, root->left, targetSum - root->val);
            Recur(ans, temp, root->right, targetSum - root->val);
        }

        // Backtracking step
        temp.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;
        Recur(ans, temp, root, targetSum);
        return ans;
    }
};
