#include <bits/stdc++.h>
using namespace std;

/*
    Problem: Construct Binary Tree from Inorder and Postorder Traversal
    Platform: LeetCode
    Difficulty: Medium

    Approach:
    1. The last element of the postorder array represents the root node.
    2. Using the inorder array, find the position of this root value.
    3. All elements to the left of this position belong to the left subtree,
       and all elements to the right belong to the right subtree.
    4. Recursively build the right subtree first (because we are traversing 
       postorder from the end: Left → Right → Root).
    5. Then recursively build the left subtree.
    6. Maintain a hashmap to store inorder indices for O(1) lookup.

    Time Complexity: O(N)
        - Each node is created once.
        - Inorder index lookup is O(1) using hashmap.

    Space Complexity: O(N)
        - For recursion stack and hashmap.

    Key Intuition:
    🔁 Postorder gives you the *root first (from the end)*, 
    while inorder helps you divide the tree into *left and right subtrees*.
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
    TreeNode* build(vector<int>& postorder, vector<int>& inorder,
                    unordered_map<int, int>& inorderIndex,
                    int& postIndex, int inStart, int inEnd) {
        if (inStart > inEnd) return nullptr;

        int rootVal = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootVal);

        int inIndex = inorderIndex[rootVal];

        // Build right subtree first (since we’re going from end of postorder)
        root->right = build(postorder, inorder, inorderIndex, postIndex, inIndex + 1, inEnd);
        root->left = build(postorder, inorder, inorderIndex, postIndex, inStart, inIndex - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inorderIndex;
        for (int i = 0; i < inorder.size(); i++) {
            inorderIndex[inorder[i]] = i;
        }

        int postIndex = postorder.size() - 1;
        return build(postorder, inorder, inorderIndex, postIndex, 0, inorder.size() - 1);
    }
};
