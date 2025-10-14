#include <bits/stdc++.h>
using namespace std;

/*
    Problem: Binary Search Tree Iterator
    Platform: LeetCode / DSA Tracker

    Approach:
        - Use a stack to simulate in-order traversal iteratively.
        - Always push the leftmost path (from root to the smallest node) into the stack.
        - On calling next():
            → Pop the top node (which is the next smallest element).
            → Push all left nodes from its right subtree.
        - hasNext() simply checks if the stack is non-empty.

    Time Complexity:
        - next():   Amortized O(1)
        - hasNext(): O(1)
        - Overall traversal: O(N)
    Space Complexity: O(H), where H = height of the tree (stack size)
*/

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

/* BST Iterator Implementation */
class BSTIterator {
public:
    stack<TreeNode*> st;

    // Helper function: pushes all left nodes to the stack
    void pushAll(TreeNode* node) {
        for (; node != nullptr; st.push(node), node = node->left);
    }

    // Constructor initializes the iterator
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    // Returns the next smallest element
    int next() {
        TreeNode* temp = st.top();
        st.pop();
        pushAll(temp->right);
        return temp->val;
    }
    
    // Checks if the iterator has more elements
    bool hasNext() {
        return !st.empty();
    }
};

/*
    Example usage:
    BSTIterator* obj = new BSTIterator(root);
    int param_1 = obj->next();
    bool param_2 = obj->hasNext();
*/

