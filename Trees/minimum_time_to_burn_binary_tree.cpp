#include <bits/stdc++.h>
using namespace std;

/*
    Problem: Minimum Time to Burn a Binary Tree
    Platform: GFG
    Difficulty: Medium

    Approach:
    1. Perform a BFS traversal to build a parent map for each node and 
       simultaneously find the target node.
    2. Use another BFS starting from the target node to simulate the burning process.
    3. At each level of BFS, fire spreads to the node’s left child, right child, 
       and its parent (if not visited).
    4. Each BFS level corresponds to 1 second. 
       The total burning time = count of BFS levels - 1.

    Time Complexity: O(N)   // Each node is processed once
    Space Complexity: O(N)  // For queue, parent map, and visited map
*/


class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    int minTime(Node* root, int target) {
        unordered_map<int, Node*> parent;
        queue<Node*> q;
        Node* targetnode = nullptr;

        q.push(root);

        // Step 1: Build parent mapping and locate the target node
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto top = q.front();
                q.pop();

                if (top->data == target) targetnode = top;

                if (top->left) {
                    parent[top->left->data] = top;
                    q.push(top->left);
                }
                if (top->right) {
                    parent[top->right->data] = top;
                    q.push(top->right);
                }
            }
        }

        // Step 2: Simulate burning process using BFS
        unordered_map<int, int> visited;
        q.push(targetnode);
        int count = 0;

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto top = q.front();
                q.pop();
                visited[top->data] = 1;

                if (top->left && !visited[top->left->data]) {
                    q.push(top->left);
                }
                if (top->right && !visited[top->right->data]) {
                    q.push(top->right);
                }
                if (parent[top->data] && !visited[parent[top->data]->data]) {
                    q.push(parent[top->data]);
                }
            }
            count++;
        }

        return count - 1; // Subtract 1 since the first level is the starting node
    }
};
