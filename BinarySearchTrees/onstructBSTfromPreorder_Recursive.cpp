/****************************************************
 * Topic      : Binary Search Tree (BST)
 * Problem    : Construct BST from Preorder Traversal
 * Approach   : Recursive using Value Bounds (Optimal)
 * Leetcode   : 1008. Construct Binary Search Tree from Preorder Traversal
 * Difficulty : Medium
 * 
 * --------------------------------------------------
 * 🧠 Intuition:
 * In preorder traversal, nodes are visited as:
 *     → [Root, Left Subtree, Right Subtree]
 * 
 * We can rebuild the BST by leveraging the BST property:
 *     → left child < root < right child
 * 
 * During preorder traversal reconstruction:
 * - Maintain an index `i` to track current node in preorder.
 * - Maintain an upper bound (limit) for each subtree.
 * - If the current value exceeds the bound → it doesn’t belong here.
 * 
 * --------------------------------------------------
 * ⚙️ Approach (Recursive with Bound Check):
 * 1. Start from the first element (root).
 * 2. Recursively build the left subtree 
 *    with bound = current node’s value.
 * 3. Recursively build the right subtree 
 *    with bound = parent’s upper limit.
 * 4. Stop recursion when index exceeds size 
 *    or value > bound.
 * 
 * --------------------------------------------------
 * ⏱️ Time Complexity:
 *   O(N) — Each node is visited exactly once.
 * 
 * 💾 Space Complexity:
 *   O(H) — recursion stack, where H = tree height
 *   → O(log N) for balanced BST
 *   → O(N) for skewed BST
 * 
 * --------------------------------------------------
 * 🧩 Example:
 * Input: preorder = [8,5,1,7,10,12]
 * Output: [8,5,10,1,7,null,12]
 * 
 * --------------------------------------------------
 * 📘 Notes:
 * - More efficient than iterative O(N²) approach.
 * - Uses preorder properties directly.
 * - Elegant and minimal extra memory.
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
    int i = 0;

    TreeNode* buildBST(vector<int>& preorder, int bound) {
        if (i == preorder.size() || preorder[i] > bound)
            return nullptr;

        TreeNode* root = new TreeNode(preorder[i++]);
        root->left = buildBST(preorder, root->val);
        root->right = buildBST(preorder, bound);
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return buildBST(preorder, INT_MAX);
    }
};
    