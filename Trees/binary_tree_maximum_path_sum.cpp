/*
Approach:
- We use recursion (DFS) to compute the maximum gain from each subtree.
- At each node:
    - Recursively compute the maximum path sum from the left and right child.
    - Only consider positive contributions (if a subtree path sum is negative, discard it by taking max with 0).
    - Update the global maximum with the sum of current node value + left gain + right gain 
      (this represents the path passing through the current node).
    - Return node->val + max(left gain, right gain) to contribute upwards in recursion.
- Finally, the global maximum will store the answer.

Complexity Analysis:
- Time Complexity: O(N), since each node is visited once.
- Space Complexity: O(H), where H is the height of the tree due to recursion stack.
  Worst case: O(N) for skewed tree.

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
    int maxi = INT_MIN; // start with smallest possible value

    int Recur(TreeNode* root) {
        if (root == nullptr) return 0;
        
        // compute max path sums from left and right, ignore negatives
        int lh = max(0, Recur(root->left));
        int rh = max(0, Recur(root->right));

        // update global max: path passing through root
        maxi = max(maxi, root->val + lh + rh);

        // return max gain to parent
        return root->val + max(lh, rh);
    }

    int maxPathSum(TreeNode* root) {
        Recur(root);
        return maxi;
    }
};
