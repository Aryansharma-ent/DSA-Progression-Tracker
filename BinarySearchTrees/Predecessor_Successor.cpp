#include <bits/stdc++.h>
using namespace std;

/*
    Problem: Find Predecessor and Successor in a BST
    Platform: DSA Tracker / GeeksforGeeks
    Approach:
        1. Traverse the BST to find the key.
        2. While traversing:
           - If curr->data < key: current node can be a potential predecessor → move right.
           - If curr->data > key: current node can be a potential successor → move left.
        3. Once key is found:
           - Predecessor = maximum node in left subtree (rightmost node of left subtree)
           - Successor   = minimum node in right subtree (leftmost node of right subtree)
        4. Return both nodes.

    Time Complexity: O(h) → where h is the height of the BST
    Space Complexity: O(1)
*/

/* BST Node Definition */
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

/* Solution Class */
class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        Node* successor = nullptr;
        Node* predecessor = nullptr;
        
        Node* curr = root;
        while (curr) {
            if (curr->data < key) {
                predecessor = curr;
                curr = curr->right;
            }
            else if (curr->data > key) {
                successor = curr;
                curr = curr->left;
            }
            else {
                // Found the key → check subtrees
                if (curr->left) {
                    Node* temp = curr->left;
                    while (temp->right)
                        temp = temp->right;
                    predecessor = temp;
                }

                if (curr->right) {
                    Node* temp = curr->right;
                    while (temp->left)
                        temp = temp->left;
                    successor = temp;
                }

                break;
            }
        }
        return {predecessor, successor};
    }
};
