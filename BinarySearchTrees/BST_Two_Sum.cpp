#include <bits/stdc++.h>
using namespace std;

/*
    Problem: Two Sum IV - Input is a BST
    Platform: LeetCode / DSA Tracker
    Problem No: 653

    Approach:
        1. Perform an inorder traversal of the BST.
           → This gives a sorted list of all node values.
        2. Use the two-pointer technique on this sorted list:
           → If sum of values < k → move left pointer right.
           → If sum of values > k → move right pointer left.
           → If sum == k → pair found → return true.
        3. If no pair found, return false.

    Time Complexity: O(N)
        - O(N) for inorder traversal
        - O(N) for two-pointer scan
    Space Complexity: O(N)
        - To store inorder traversal of all nodes
*/

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

    // Helper function: Inorder traversal to get sorted BST values
    void Recur(TreeNode* root, vector<int> &inorder) {
        if (root == nullptr) return;

        Recur(root->left, inorder);
        inorder.push_back(root->val);
        Recur(root->right, inorder);
    }

    // Main function: Find if any two elements sum to k
    bool findTarget(TreeNode* root, int k) {
        vector<int> inorder;
        Recur(root, inorder);

        int left = 0;
        int right = inorder.size() - 1;

        while (left < right) {
            int sum = inorder[left] + inorder[right];
            if (sum < k) left++;
            else if (sum > k) right--;
            else return true;
        }

        return false;
    }
};
