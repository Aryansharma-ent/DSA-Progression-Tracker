#include <bits/stdc++.h>
using namespace std;

/*
    Problem: Count Nodes in a Complete Binary Tree
    Platform: LeetCode
    Difficulty: Medium

    Approach:
    1. For each node, compute the height of its leftmost and rightmost paths.
    2. If both heights are equal, it means the subtree is perfect → 
       total nodes = (1 << height) - 1.
    3. Otherwise, recursively count nodes in the left and right subtrees.
    4. This avoids visiting all nodes and leverages the structural property 
       of Complete Binary Trees.

    Time Complexity: O(log²N)
        - Each recursive call computes height in O(log N)
        - Height computation occurs for O(log N) levels

    Space Complexity: O(log N)
        - Due to recursion stack (tree height)

    Key Intuition:
    🌲 In a Complete Binary Tree, if left and right heights are equal, 
    that subtree is perfectly filled, so we can use the direct node formula 
    instead of traversing all nodes.
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int CountLeft(TreeNode* node) {
        int height = 0;
        while (node) {
            height++;
            node = node->left;
        }
        return height;
    }

    int CountRight(TreeNode* node) {
        int height = 0;
        while (node) {
            height++;
            node = node->right;
        }
        return height;
    }

    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;

        int lh = CountLeft(root);
        int rh = CountRight(root);

        // If both heights are equal → perfect binary tree
        if (lh == rh)
            return (1 << lh) - 1;

        // Otherwise, recursively count left and right subtrees
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
