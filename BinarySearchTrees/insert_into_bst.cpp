#include <bits/stdc++.h>
using namespace std;

/*
    Problem: Insert into a Binary Search Tree
    Platform: LeetCode
    Difficulty: Medium

    Approach (Iterative):
    1. If the tree is empty, simply return a new node with value `val`.
    2. Start from the root and traverse down the tree:
        - If `val < node->val`, move left.
            - If the left child is NULL, insert the new node here.
        - Else, move right.
            - If the right child is NULL, insert the new node here.
    3. Continue until the correct insertion point is found.

    Time Complexity: O(H)
        - Where H = height of the BST.
        - O(log N) for balanced BST, O(N) for skewed.

    Space Complexity: O(1)
        - No recursion used (iterative approach).

    Key Intuition:
    🌳 In a BST, all nodes in the left subtree are smaller and 
        all nodes in the right subtree are larger. 
        Keep traversing until a valid insertion spot is found.
*/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == NULL) return new TreeNode(val);
        
        TreeNode* node = root;
        while (node) {
            if (val < node->val) {
                if (node->left != NULL) {
                    node = node->left;
                } else {
                    node->left = new TreeNode(val);
                    break;
                }
            } else {
                if (node->right != NULL) {
                    node = node->right;
                } else {
                    node->right = new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }
};
