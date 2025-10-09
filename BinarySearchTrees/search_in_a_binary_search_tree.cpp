#include <bits/stdc++.h>
using namespace std;

/*
    Problem: Search in a Binary Search Tree
    Platform: LeetCode
    Difficulty: Easy

    Approach:
    1. Use recursion to traverse the BST.
    2. At each node:
       - If the current node is NULL or its value equals the target → return it.
       - If target < current node’s value → search in the left subtree.
       - Otherwise → search in the right subtree.
    3. The BST property ensures O(log N) average time since each step halves the search space.

    Time Complexity:
        - Average Case: O(log N)
        - Worst Case (skewed tree): O(N)

    Space Complexity:
        - O(H) due to recursion stack (H = height of the tree)

    Key Intuition:
    🌿 Binary Search Tree allows directional search — 
    we can skip half of the tree each time based on the current node’s value.
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr || root->val == val) 
            return root;

        if (val < root->val)
            return searchBST(root->left, val);
        else
            return searchBST(root->right, val);
    }
};
