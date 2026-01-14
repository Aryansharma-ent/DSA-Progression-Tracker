/*
Problem: Minimum Depth of Binary Tree
Platform: LeetCode
Problem No: 111

Problem Statement:
Given the root of a binary tree, return its minimum depth.
The minimum depth is the number of nodes along the shortest path
from the root node down to the nearest leaf node.

Note:
A leaf is a node with no children.

Approach:
- Use recursion (Depth First Search).
- Compute the minimum depth of left and right subtrees.
- Special handling is required when one child is NULL:
  - If one subtree is empty, the path must go through the non-empty subtree.
- If both subtrees exist, take the minimum of the two.

Why this works:
- DFS explores all paths from root to leaf.
- Correctly handles skewed trees where one side is missing.
- Avoids counting invalid paths through NULL children.

Time Complexity:
- O(N), where N is the number of nodes in the tree.
  Each node is visited once.

Space Complexity:
- O(H), where H is the height of the tree (recursion stack).
  Worst case: O(N) for a skewed tree.

Edge Cases:
- Empty tree → depth = 0
- Single node tree → depth = 1
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
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;

        int lh = minDepth(root->left);
        int rh = minDepth(root->right);

        // If one subtree is empty, take the depth of the other
        if (lh == 0) return 1 + rh;
        if (rh == 0) return 1 + lh;

        return 1 + min(lh, rh);
    }
};
