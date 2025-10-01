/**
 * Problem: Binary Tree Zigzag Level Order Traversal (LeetCode 103)
 *
 * Approach:
 *  - Perform a standard level-order traversal (BFS) using a queue.
 *  - For each level, pre-allocate a vector of size equal to the level size.
 *  - Insert node values either left-to-right or right-to-left depending on the current level.
 *  - Use a boolean flag `leftToRight` that flips after processing each level.
 *
 * Why this approach:
 *  - Avoids reversing vectors at every odd level (O(k) per level).
 *  - Directly places values in correct positions, making it more efficient in practice.
 *
 * Complexity:
 *  - Time Complexity: O(N), where N is the number of nodes (each node is processed once).
 *  - Space Complexity: O(N), for the queue and the result storage.
 *
 * N = number of nodes in the binary tree
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;

        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;

        while (!q.empty()) {
            int size = q.size();
            vector<int> temp(size);

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                // Place value according to direction
                int index = leftToRight ? i : (size - 1 - i);
                temp[index] = node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            ans.push_back(temp);
            leftToRight = !leftToRight; // flip direction for next level
        }

        return ans;
    }
};
