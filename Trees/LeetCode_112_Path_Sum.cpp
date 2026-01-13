/*
Problem: Path Sum
Platform: LeetCode
Problem No: 112

Problem Statement:
Given the root of a binary tree and an integer targetSum, return true if the tree
has a root-to-leaf path such that the sum of the values along the path equals
targetSum.

A root-to-leaf path means a path starting from the root and ending at any leaf node.

Approach:
- Use Depth First Search (DFS) with recursion.
- Maintain a running sum of node values while traversing from root to leaf.
- When a leaf node is reached, check if the accumulated sum equals targetSum.
- Backtrack by removing the current node's value from the running sum.
- If any valid path is found, return true.

Why this works:
- DFS explores all root-to-leaf paths.
- Backtracking ensures each path is evaluated independently.
- As soon as one valid path is found, the result can be considered true.

Time Complexity:
- O(N), where N is the number of nodes in the tree.
  Each node is visited once.

Space Complexity:
- O(H), where H is the height of the tree (recursion stack).
  Worst case: O(N) for a skewed tree.

Edge Case:
- If the tree is empty, no root-to-leaf path exists → return false.
*/

 #include <bits/stdc++.h>
 using namespace std;
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
    long long sum = 0;

    int Recur(TreeNode* root, int targetSum) {
        if (root == nullptr) return 0;

        sum += root->val;
        int found = 0;

        // Check leaf node
        if (root->left == nullptr && root->right == nullptr) {
            if (sum == targetSum) found = 1;
        } else {
            found += Recur(root->left, targetSum);
            found += Recur(root->right, targetSum);
        }

        // Backtrack
        sum -= root->val;
        return found;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        return (Recur(root, targetSum) >= 1);
    }
};
