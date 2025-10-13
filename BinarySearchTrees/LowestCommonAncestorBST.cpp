/****************************************************
 * Topic      : Binary Search Tree (BST)
 * Problem    : Lowest Common Ancestor in a BST
 * Leetcode   : 235. Lowest Common Ancestor of a Binary Search Tree
 * Difficulty : Medium
 * 
 * --------------------------------------------------
 * 🧠 Intuition:
 * In a Binary Search Tree, all left nodes have smaller values,
 * and all right nodes have greater values than the root.
 * The Lowest Common Ancestor (LCA) is the node where:
 *   - one node lies in the left subtree
 *   - the other lies in the right subtree
 * OR
 *   - the current node itself matches either p or q.
 * 
 * --------------------------------------------------
 * ⚙️ Approach (Iterative - Optimized):
 * 1. Ensure p->val <= q->val by swapping if needed.
 * 2. Traverse the BST starting from the root.
 * 3. If both nodes are smaller than root → move left.
 * 4. If both nodes are greater than root → move right.
 * 5. Else, root is the LCA.
 * 
 * --------------------------------------------------
 * ⏱️ Time Complexity:
 *   O(h), where h = height of the BST
 *   → O(log N) for balanced BST
 *   → O(N) for skewed BST
 * 
 * 💾 Space Complexity:
 *   O(1), iterative approach (no recursion stack)
 * 
 * --------------------------------------------------
 * 🧩 Alternate Approach (Recursive):
 * - Use recursion instead of iteration.
 * - Same logic: compare values and traverse left/right.
 * - Space Complexity: O(h) due to recursion stack.
 * 
 * --------------------------------------------------
 * ✅ Example:
 * Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
 * Output: 6
 * Explanation: LCA of nodes 2 and 8 is 6.
 * 
 * --------------------------------------------------
 * 📘 Notes:
 * - Works only for BST (not for generic binary trees).
 * - For non-BSTs, you’d need a different LCA approach
 *   (traverse both sides and return the first common node).
 ****************************************************/

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Ensure p->val <= q->val
        if (p->val > q->val) swap(p, q);

        while (root) {
            if (root->val > q->val)
                root = root->left;   // both nodes lie in left subtree
            else if (root->val < p->val)
                root = root->right;  // both nodes lie in right subtree
            else
                return root;         // found the LCA
        }

        return nullptr; // no LCA found
    }
};
