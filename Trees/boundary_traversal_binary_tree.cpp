/*******************************************************
 * Problem: Boundary Traversal of Binary Tree
 * 
 * Approach:
 *  - Use three helper functions:
 *    1. addLeftBoundary() → Traverse the left boundary (excluding leaves).
 *    2. addLeaves() → Collect all leaf nodes.
 *    3. addRightBoundary() → Traverse the right boundary (excluding leaves) in reverse.
 *  - Ensure that leaves are not duplicated.
 * 
 * Time Complexity:
 *  - O(N) → Each node is visited at most once.
 * 
 * Space Complexity:
 *  - O(N) → Result vector + recursion stack (in case of skewed tree).
 * 
 * Bits:
 *  - Boundary nodes are collected in anti-clockwise order:
 *    Root → Left Boundary → Leaves → Right Boundary
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
    bool isLeaf(Node* root) {
        return !root->left && !root->right;
    }

    void addLeftBoundary(Node* root, vector<int> &res) {
        Node* cur = root->left;
        while (cur) {
            if (!isLeaf(cur)) res.push_back(cur->data);
            if (cur->left) cur = cur->left;
            else cur = cur->right;
        }
    }

    void addLeaves(Node* root, vector<int> &res) {
        if (isLeaf(root)) {
            res.push_back(root->data);
            return;
        }
        if (root->left) addLeaves(root->left, res);
        if (root->right) addLeaves(root->right, res);
    }

    void addRightBoundary(Node* root, vector<int> &res) {
        Node* cur = root->right;
        vector<int> temp;
        while (cur) {
            if (!isLeaf(cur)) temp.push_back(cur->data);
            if (cur->right) cur = cur->right;
            else cur = cur->left;
        }
        for (int i = temp.size() - 1; i >= 0; i--) {
            res.push_back(temp[i]);
        }
    }

    vector<int> boundaryTraversal(Node* root) {
        vector<int> res;
        if (!root) return res;
        if (!isLeaf(root)) res.push_back(root->data);
        addLeftBoundary(root, res);
        addLeaves(root, res);
        addRightBoundary(root, res);
        return res;
    }
};
