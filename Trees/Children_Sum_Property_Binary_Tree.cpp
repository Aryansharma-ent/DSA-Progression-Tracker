/*
------------------------------------------------------------
🧩 Problem: Children Sum Property in a Binary Tree
📘 Topic: Binary Trees | Recursion
🕒 Time Complexity: O(N)
🧮 Space Complexity: O(H)  // H = height of tree
------------------------------------------------------------
✅ Approach:
1. If node is NULL → return 0.
2. If node is a leaf → return its value.
3. Recursively find sum from left & right child.
4. If either subtree is invalid (returns -1) → propagate -1.
5. If current node’s value != sum of its children → invalid (-1).
6. Else return current node’s value.
------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
  int recur(Node* root) {
      if (!root) return 0;
      if (!root->left && !root->right) return root->data;
      
      int lh = recur(root->left);
      int rh = recur(root->right);
      
      if (lh == -1 || rh == -1) return -1;
      if (root->data != lh + rh) return -1;
      
      return root->data;
  }
  
  int isSumProperty(Node *root) {
      return recur(root) != -1;
  }
};
