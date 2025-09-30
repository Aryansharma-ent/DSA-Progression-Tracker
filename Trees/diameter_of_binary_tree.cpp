/*
Approach:
- We use recursion to calculate the height of each subtree.
- While calculating height, we compute the possible diameter passing through that node as the sum of left height + right height.
- We keep track of the maximum diameter found so far in a global variable.
- Finally, return the maximum diameter.

Complexity Analysis:
- Time Complexity: O(N), where N is the number of nodes in the tree (each node is visited once).
- Space Complexity: O(H), where H is the height of the tree due to recursion stack. 
  In the worst case (skewed tree), O(N).

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
    int maxdia = 0;

    int Recur(TreeNode* root) {
        if (root == nullptr) return 0;
        int lh = Recur(root->left);
        int rh = Recur(root->right);
        maxdia = max(maxdia, lh + rh);
        return 1 + max(lh, rh);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        Recur(root);
        return maxdia;
    }
};
