/*
    Problem: Symmetric Tree (Mirror Image of Itself)
    -----------------------------------------------
    Given the root of a binary tree, check whether it is symmetric
    around its center (i.e., whether the left subtree is a mirror reflection
    of the right subtree).

    Approach:
    ---------
    - Define a helper function `isMirror(t1, t2)`:
        * If both t1 and t2 are null → return true.
        * If only one is null → return false.
        * Otherwise, check:
            1. t1->val == t2->val
            2. Left subtree of t1 is a mirror of Right subtree of t2
            3. Right subtree of t1 is a mirror of Left subtree of t2
    - In the main function `isSymmetric`, simply call isMirror on
      root->left and root->right.

    Complexity:
    -----------
    - Time Complexity: O(N)
        * N = number of nodes in the tree. Each node is visited once.
    - Space Complexity: O(H)
        * H = height of tree, due to recursion stack.
        * Worst case (skewed tree): O(N), Best/Average (balanced): O(log N).

    Example:
    --------
            1
           / \
          2   2
         / \ / \
        3  4 4  3

    Output: true (symmetric)
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
    bool isMirror(TreeNode* t1, TreeNode* t2) {
        if (!t1 && !t2) return true;       // both null -> symmetric
        if (!t1 || !t2) return false;      // one null, other not -> not symmetric
        return (t1->val == t2->val) && 
               isMirror(t1->left, t2->right) && 
               isMirror(t1->right, t2->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (!root) return true;  // empty tree is symmetric
        return isMirror(root->left, root->right);
    }
};
