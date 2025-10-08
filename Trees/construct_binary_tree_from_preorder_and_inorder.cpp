#include <bits/stdc++.h>
using namespace std;

/*
    Problem: Construct Binary Tree from Preorder and Inorder Traversal
    Platform: LeetCode
    Difficulty: Medium

    Approach:
    1. The first element of the preorder array is always the root.
    2. Using a HashMap (unordered_map), store indices of inorder elements for O(1) lookup.
    3. Recursively build:
        - Left subtree → elements before root index in inorder.
        - Right subtree → elements after root index in inorder.
    4. Maintain a global/reference preorder index to track the current root.
    5. Stop recursion when inStart > inEnd.

    Time Complexity: O(N)
        - Each node is created once.
        - HashMap lookups are O(1).

    Space Complexity: O(N)
        - HashMap for inorder indices.
        - Recursion stack (height of tree).

    Key Intuition:
    🌳 Preorder gives the root order, and inorder gives the left-right boundaries.
    Combining both lets us uniquely reconstruct the tree structure efficiently.
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* build(vector<int>& preorder, vector<int>& inorder,
                    unordered_map<int, int>& inorderIndex,
                    int& preIndex, int inStart, int inEnd) {
        if (inStart > inEnd) return nullptr;

        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);

        int inIndex = inorderIndex[rootVal];

        root->left = build(preorder, inorder, inorderIndex, preIndex, inStart, inIndex - 1);
        root->right = build(preorder, inorder, inorderIndex, preIndex, inIndex + 1, inEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorderIndex;
        for (int i = 0; i < inorder.size(); i++) {
            inorderIndex[inorder[i]] = i;
        }

        int preIndex = 0;
        return build(preorder, inorder, inorderIndex, preIndex, 0, inorder.size() - 1);
    }
};
