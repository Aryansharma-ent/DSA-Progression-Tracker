/**
 * Problem: Binary Tree Paths
 * LeetCode: https://leetcode.com/problems/binary-tree-paths/
 * 
 * Approach:
 * - We perform a DFS traversal from the root.
 * - Maintain a `temp` string that builds the current path.
 * - At each step, append the current node’s value.
 * - If the node is a leaf (no left & right child), push the path into the result vector.
 * - Otherwise, recursively call for left and right subtrees.
 * 
 * Why it works:
 * - The recursive DFS ensures all root-to-leaf paths are explored.
 * - String concatenation ensures paths are correctly formatted with `"->"`.
 * 
 * Time Complexity: O(N * H)
 *   - Each node is visited once → O(N).
 *   - Path string building can take O(H) per leaf (H = height of tree).
 *   - Worst case: skewed tree → O(N^2), average case better.
 * 
 * Space Complexity: O(H)
 *   - Recursion stack can go as deep as tree height H.
 *   - Additional vector stores all paths → O(N * H) in worst case.
 * 
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
    void Recur(TreeNode* root, string temp, vector<string> &ans) {
        if (root == NULL) return;

        // Build the path string
        if (temp.empty()) temp += to_string(root->val);
        else temp += "->" + to_string(root->val);

        // If leaf node, store the path
        if (!root->left && !root->right) {
            ans.push_back(temp);
            return;
        }

        // Recur for left and right children
        Recur(root->left, temp, ans);
        Recur(root->right, temp, ans);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        Recur(root, "", ans);
        return ans;
    }
};
