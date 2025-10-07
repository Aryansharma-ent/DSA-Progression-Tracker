/*
------------------------------------------------------------
🧩 Problem: Nodes at Distance K in a Binary Tree
📘 Topic: Binary Trees | BFS | Hashing | Parent Mapping
🕒 Time Complexity: O(N)
🧮 Space Complexity: O(N)
------------------------------------------------------------
✅ Approach:
1. **Build Parent Map:**  
   - Use BFS to map each node’s value to its parent node.
2. **Perform BFS from Target Node:**  
   - Start from the target and explore in all 3 directions:
     ➤ Left child  
     ➤ Right child  
     ➤ Parent
3. Use a `visited` map to avoid revisiting nodes.
4. Decrease `k` level by level until it reaches 0.
5. The remaining nodes in the queue are exactly at distance K.
------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        unordered_map<int, TreeNode*> parent;
        queue<TreeNode*> q;
        q.push(root);

        // Step 1: Build parent mapping using BFS
        while (!q.empty()) {
            int si = q.size();
            for (int i = 0; i < si; i++) {
                auto top = q.front();
                q.pop();
                
                if (top->left) {
                    parent[top->left->val] = top;
                    q.push(top->left);
                }

                if (top->right) {
                    parent[top->right->val] = top;
                    q.push(top->right);
                }
            }
        }

        // Step 2: BFS from target node
        unordered_map<int, int> visited;
        q.push(target);

        while (k-- && !q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto top = q.front();
                q.pop();
                visited[top->val] = 1;

                if (top->left && !visited[top->left->val])
                    q.push(top->left);
                if (top->right && !visited[top->right->val])
                    q.push(top->right);
                if (parent[top->val] && !visited[parent[top->val]->val])
                    q.push(parent[top->val]);
            }
        }

        // Step 3: Collect all nodes at distance K
        while (!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }
};
