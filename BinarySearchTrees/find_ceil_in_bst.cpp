#include <bits/stdc++.h>
using namespace std;

/*
    Problem: Ceil in a Binary Search Tree
    Platform: GFG
    Difficulty: Easy

    Approach:
    1. Initialize an integer `ceilVal = -1` to store the potential ceil.
    2. Traverse the BST:
        - If `root->data == x`, that’s the exact ceil → return it.
        - If `root->data > x`, store it as a potential ceil and move left (since there might be a smaller valid value).
        - Else, move right (since all values on left are smaller).
    3. When traversal ends, return `ceilVal`.

    Time Complexity: O(H)  
        - Where H = height of BST  
        - O(log N) for balanced BST, O(N) for skewed

    Space Complexity: O(1)  
        - Iterative approach (no recursion stack)

    Key Intuition:
    🌿 While traversing a BST, each time we move left, 
    we record a node that could potentially be the smallest number ≥ x.
*/

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

class Solution {
  public:
    int findCeil(Node* root, int x) {
        int ceilVal = -1;
        while (root) {
            if (root->data == x) return root->data;
            if (root->data > x) {
                ceilVal = root->data;
                root = root->left;
            } else {
                root = root->right;
            }
        }
        return ceilVal;
    }
};
