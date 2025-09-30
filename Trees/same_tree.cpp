/*
Approach:
- To check if two binary trees are the same:
  1. Both nodes are null -> return true.
  2. One node is null, the other is not -> return false.
  3. Values are different -> return false.
  4. Recursively check left and right subtrees.
- This ensures both structure and values are identical.

Why not inorder?
- Inorder traversal alone cannot differentiate between different tree structures.
  Example: [2,1] can come from two different trees with root=1 and left/right child=2.

Complexity:
- Time Complexity: O(N), where N is the number of nodes (each visited once).
- Space Complexity: O(H), where H is the height of the tree (recursion stack).
*/

#include <bits/stdc++.h>
using namespace std;

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;       // both null
        if (!p || !q) return false;      // one null, one not
        if (p->val != q->val) return false; // values differ

        // recursively check left and right
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
