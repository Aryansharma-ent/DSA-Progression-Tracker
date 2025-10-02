/*******************************************************
 * Problem: Vertical Order Traversal of Binary Tree
 * 
 * Approach:
 *  - Use BFS with a queue that stores (node, vertical, level).
 *  - Maintain a map: vertical → (level → multiset of nodes).
 *  - After traversal, collect nodes from leftmost vertical
 *    to rightmost vertical, while maintaining order by level.
 * 
 * Time Complexity:
 *  - O(N logN) → due to ordered map and multiset insertions.
 * 
 * Space Complexity:
 *  - O(N) → map + queue storage.
 * 
 * Bits:
 *  - Vertical traversal groups nodes column by column.
 *  - Nodes with same vertical and level are stored in sorted order.
 *******************************************************/

#include <bits/stdc++.h>
using namespace std;

// Definition for Binary Tree Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    vector<vector<int>> verticalTraversal(Node* root) {
        // Map: vertical -> level -> multiset of nodes
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<Node*, pair<int, int>>> q; // node, vertical, level

        q.push({root, {0, 0}});

        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            Node* node = it.first;
            int x = it.second.first;  // vertical
            int y = it.second.second; // level

            nodes[x][y].insert(node->data);

            if (node->left) q.push({node->left, {x - 1, y + 1}});
            if (node->right) q.push({node->right, {x + 1, y + 1}});
        }

        vector<vector<int>> ans;
        for (auto &p : nodes) {
            vector<int> col;
            for (auto &q : p.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};
