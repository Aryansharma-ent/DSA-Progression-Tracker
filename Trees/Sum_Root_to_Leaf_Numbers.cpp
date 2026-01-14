/*
Problem: Sum Root to Leaf Numbers
Platform: LeetCode
Problem No: 129

Problem Statement:
Given the root of a binary tree containing digits from 0 to 9 only,
each root-to-leaf path represents a number.
Return the total sum of all root-to-leaf numbers.

Approach:
- Use Depth First Search (DFS) with recursion.
- Maintain a running number formed by the path from root to the current node.
- At each node:
  - Update the number as: number = number * 10 + node->val
- When a leaf node is reached:
  - Add the formed number to the total sum.
- Backtrack by removing the last digit when returning to the parent.

Why this works:
- DFS explores all root-to-leaf paths.
- Each path forms exactly one number.
- Backtracking ensures the number is correctly maintained for each path.

Time Complexity:
- O(N), where N is the number of nodes in the tree.
  Each node is visited once.

Space Complexity:
- O(H), where H is the height of the tree (recursion stack).
  Worst case: O(N) for a skewed tree.

Edge Case:
- If the tree is empty, the sum is 0.
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
    int number = 0;

    void Recur(TreeNode* root, int &sum) {
        if (root == nullptr) return;

        number = number * 10 + root->val;

        // If leaf node, add formed number to sum
        if (root->left == nullptr && root->right == nullptr) {
            sum += number;
        } else {
            Recur(root->left, sum);
            Recur(root->right, sum);
        }

        // Backtrack
        number /= 10;
    }

    int sumNumbers(TreeNode* root) {
        int sum = 0;
        Recur(root, sum);
        return sum;
    }
};
