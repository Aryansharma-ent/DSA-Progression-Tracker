/*******************************************************
 * Problem: Width of Binary Tree
 * 
 * Approach:
 *  - Perform level order traversal (BFS).
 *  - Assign indices to nodes as if the tree were a complete binary tree:
 *      left = 2*i + 1, right = 2*i + 2
 *  - For each level, compute width = (last - first + 1).
 *  - Normalize indices at every level to avoid overflow.
 * 
 * Time Complexity:
 *  - O(N) → Each node is processed once.
 * 
 * Space Complexity:
 *  - O(N) → Queue used for BFS traversal.
 * 
 * Bits:
 *  - Use unsigned long long for indices to prevent overflow.
 *******************************************************/

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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        unsigned long long ans = 0;

        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int size = q.size();
            unsigned long long minIndex = q.front().second; // base index for normalization
            unsigned long long first = 0, last = 0;

            for (int i = 0; i < size; i++) {
                unsigned long long curId = q.front().second - minIndex;
                TreeNode* node = q.front().first;
                q.pop();

                if (i == 0) first = curId;
                if (i == size - 1) last = curId;

                if (node->left) q.push({node->left, curId * 2 + 1});
                if (node->right) q.push({node->right, curId * 2 + 2});
            }

            ans = max(ans, last - first + 1);
        }

        return static_cast<int>(ans);
    }
};
