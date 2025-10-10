#include <bits/stdc++.h>
using namespace std;

/*
    Problem: Validate Binary Search Tree
    Platform: LeetCode
    Difficulty: Medium

    Approach (Recursive Range Checking):
    1. For each node, maintain a valid range `(minVal, maxVal)` that 
       its value must lie within.
    2. Initially, call the helper with range `(LONG_MIN, LONG_MAX)`.
    3. Recursively:
        - The left child must have a value < current node’s value.
        - The right child must have a value > current node’s value.
    4. If any node violates these bounds, return false.

    Time Complexity: O(N)
        - Each node is visited exactly once.

    Space Complexity: O(H)
        - Due to recursion stack (tree height), 
          where H = log N for balanced BST and N for skewed.

    Key Intuition:
    ✅ A valid BST requires **strict inequalities** — 
    every left node must be < root, and every right node must be > root, 
    not just at the immediate level but for the entire subtree.
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isValidBSTHelper(TreeNode* root, long minVal, long maxVal) {
        if (root == nullptr) return true;

        if (root->val <= minVal || root->val >= maxVal)
            return false;

        return isValidBSTHelper(root->left, minVal, root->val) &&
               isValidBSTHelper(root->right, root->val, maxVal);
    }

    bool isValidBST(TreeNode* root) {
        return isValidBSTHelper(root, LONG_MIN, LONG_MAX);
    }
};
