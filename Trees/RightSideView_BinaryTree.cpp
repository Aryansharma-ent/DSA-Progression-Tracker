/*
    Problem: Right Side View of Binary Tree
    ---------------------------------------
    Given the root of a binary tree, return the values of the nodes you can see
    from the right side, ordered from top to bottom.

    Approach:
    ---------
    - Use DFS recursion with priority to the right subtree first:
        * Keep track of the current "level".
        * If the current level is being visited for the first time,
          add the node's value to the answer.
        * Traverse right before left, so the rightmost node at each level
          is chosen first.
    - This guarantees that for each level, the first node visited is the
      rightmost node visible from that side.

    Complexity:
    -----------
    - Time Complexity: O(N)
        * N = number of nodes, since we visit each node once.
    - Space Complexity: O(H)
        * H = height of the tree (recursive stack). In worst case (skewed tree), O(N).

    Example:
    --------
            1
           / \
          2   3
           \    \
            5    4

    Right Side View: [1, 3, 4]
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
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void Recur(TreeNode* root, vector<int> &ans, int level) {
        if (root == nullptr) return;

        // First time we reach this level → take the node value
        if (level == ans.size()) {
            ans.push_back(root->val);
        }

        // Traverse right first for right-side priority
        Recur(root->right, ans, level + 1);
        Recur(root->left, ans, level + 1);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        Recur(root, ans, 0);
        return ans;
    }
};
