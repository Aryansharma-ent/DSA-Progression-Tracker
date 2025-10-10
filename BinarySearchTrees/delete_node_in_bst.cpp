#include <bits/stdc++.h>
using namespace std;

/*
    Problem: Delete Node in a Binary Search Tree
    Platform: LeetCode
    Difficulty: Medium

    Approach (Iterative + Helper Function):
    1. Define a helper function that handles the deletion logic:
        - If the node has no left child → return its right child.
        - If the node has no right child → return its left child.
        - If the node has both children:
            - Find the rightmost node in the left subtree (`LeftLastChild`).
            - Attach the right subtree to this node’s right.
            - Return the left subtree (new root of this subtree).

    2. In the main function:
        - If the `root` is NULL → return NULL.
        - If the `root` itself is the node to be deleted → directly call `helper(root)`.
        - Otherwise, traverse the tree iteratively:
            - If `key` < `root->val`, look in the left subtree.
            - If `key` > `root->val`, look in the right subtree.
            - When the matching child node is found, replace it with `helper(child)`.

    Time Complexity: O(H)
        - Where H = height of BST.
        - O(log N) for balanced BST, O(N) for skewed.

    Space Complexity: O(1)
        - Iterative traversal and pointer rearrangements only.

    Key Intuition:
    🌳 The deletion in BST depends on the number of children.
        We rearrange links such that BST properties remain valid
        after removing the target node.
*/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* LeftLastChild(TreeNode* root) {
        if (root->right == NULL) {
            return root;
        }
        return LeftLastChild(root->right);
    }

    TreeNode* helper(TreeNode* root) {
        if (root->left == NULL) {
            return root->right;
        } else if (root->right == NULL) {
            return root->left;
        } else {
            TreeNode* rightChild = root->right;
            TreeNode* LeftLast = LeftLastChild(root->left);
            LeftLast->right = rightChild;
            return root->left;
        }
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return nullptr;
        if (root->val == key) return helper(root);

        TreeNode* dummy = root;
        while (root != NULL) {
            if (root->val > key) {
                if (root->left != NULL && root->left->val == key) {
                    root->left = helper(root->left);
                    break;
                } else {
                    root = root->left;
                }
            } else {
                if (root->right != NULL && root->right->val == key) {
                    root->right = helper(root->right);
                    break;
                } else {
                    root = root->right;
                }
            }
        }
        return dummy;
    }
};
