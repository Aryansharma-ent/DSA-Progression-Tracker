/*
Problem: Binary Tree Level Order Traversal II
Platform: LeetCode
Problem No: 107

Problem Statement:
Given the root of a binary tree, return the bottom-up level order traversal
of its nodes' values. (i.e., from left to right, level by level from leaf to root).

Approach:
- Use Breadth First Search (BFS) with a queue to traverse the tree level by level.
- For each level:
  - Store all node values in a temporary vector.
  - Push children nodes into the queue for the next level.
- Store each level’s result in a vector.
- After BFS traversal is complete, reverse the result to get bottom-up order.

Why this works:
- BFS naturally processes nodes level by level.
- Reversing the final result is simpler and more efficient than inserting
  each level at the front.

Time Complexity:
- O(N), where N is the number of nodes in the tree.
  Each node is visited exactly once.

Space Complexity:
- O(N), for the queue and the result storage.

Edge Case:
- If the tree is empty (root == nullptr), return an empty vector.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;

        if (root == nullptr) return ans;

        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector<int> temp;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);

                temp.push_back(node->val);
            }

            ans.push_back(temp);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
