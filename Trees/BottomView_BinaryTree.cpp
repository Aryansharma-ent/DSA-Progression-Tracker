/*
    Problem: Bottom View of Binary Tree
    -----------------------------------
    Given the root of a binary tree, return the bottom view of the tree.

    Approach:
    ---------
    - Assign a "horizontal distance (hd)" to each node:
        * Root has hd = 0
        * Left child has hd = parent.hd - 1
        * Right child has hd = parent.hd + 1
    - Perform a BFS (level order traversal).
    - For each hd, update (overwrite) the node value in a map<int,int>.
      This ensures that the **last node encountered** at that horizontal
      distance is stored, which corresponds to the bottom-most node visible.
    - Finally, traverse the map (which keeps keys sorted) and collect the
      bottom view in left-to-right order.

    Complexity:
    -----------
    - Time Complexity: O(N log N)
        * N = number of nodes
        * log N due to insertion/update in map for each node.
    - Space Complexity: O(N)
        * For queue (BFS) + map storage.

    Example:
    --------
            20
           /  \
          8   22
         / \     \
        5  3     25
          / \
         10 14

    Bottom View: 5 10 3 14 25
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
    vector<int> bottomView(Node *root) {
        vector<int> ans;
        if (!root) return ans;

        map<int,int> mp; // hd -> node value
        queue<pair<Node*,int>> q;
        q.push({root,0});

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            Node* node = it.first;
            int line = it.second;

            // overwrite ensures bottom-most node stays
            mp[line] = node->data;

            if(node->left != nullptr){
                q.push({node->left, line-1});
            }
            if(node->right != nullptr){
                q.push({node->right, line+1});
            }
        }

        for(auto it: mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
