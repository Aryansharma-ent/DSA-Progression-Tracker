/*
    Problem: Binary Tree Level Order Traversal (LeetCode 102)

    Approach:
    - Use Breadth First Search (BFS) with a queue.
    - Start by pushing the root node into the queue.
    - While the queue is not empty:
        1. Take the current queue size (number of nodes in this level).
        2. For each node at this level:
            - Pop it from the queue.
            - Push its left and right children into the queue (if they exist).
            - Add its value to the current level vector.
        3. Push the current level vector into the answer.
    - This ensures nodes are visited level by level.

    Time Complexity:
    - O(N), where N is the number of nodes in the tree.
    - Each node is enqueued and dequeued once.

    Space Complexity:
    - O(N), due to the queue and the result vector.
    - In the worst case, the queue may contain O(N/2) ≈ O(N) nodes (last level).
*/

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) return ans;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector<int> temp;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);

                temp.push_back(node->val);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};
