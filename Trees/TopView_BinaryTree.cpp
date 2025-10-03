/*
    Problem: Top View of Binary Tree
    --------------------------------
    Given the root of a binary tree, return the top view of the tree.

    Approach:
    ---------
    - The idea is to assign a "horizontal distance (hd)" to each node:
        * Root has hd = 0
        * Left child has hd = parent.hd - 1
        * Right child has hd = parent.hd + 1
    - We perform a BFS (level order traversal) to ensure we visit nodes 
      level by level (top to bottom).
    - For each horizontal distance, we record the **first node** encountered
      (since it will be visible from the top).
    - Use a map<int,int> to store hd → node value. Map keeps keys sorted,
      so final answer can be extracted in left-to-right order.

    Complexity:
    -----------
    - Time Complexity: O(N log N)
        * N = number of nodes
        * log N due to insertion in map for each node.
    - Space Complexity: O(N)
        * For queue (BFS) + map storage.

    Example:
    --------
            1
           / \
          2   3
           \
            4
             \
              5
               \
                6

    Top View: 2 1 3 6
*/

#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
  public:
    vector<int> topView(Node *root) {
        vector<int> ans;
        if(root == nullptr) return ans;

        map<int,int> mp;  // hd -> node value
        queue<pair<Node*,int>> q;

        q.push({root,0});

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            Node* node = it.first;
            int line = it.second;

            if(mp.find(line) == mp.end()){
                mp[line] = node->data;
            }

            if(node->left != nullptr){
                q.push({node->left, line-1});
            }
            if(node->right != nullptr){
                q.push({node->right, line+1});
            }
        }

        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
