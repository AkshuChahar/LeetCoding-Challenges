/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    // Initialise 3 pointers.
    TreeNode *first, *last, *prev;

    void recoverTree(TreeNode* root) {
        // Make all the pointers NULL.
        first = last = prev = NULL;
        // Do the Inorder traversal.
        inorder(root);
        // Swap the values of 'first' and 'last' pointers.
        swap(first->val, last->val);
    }

    // Inorder traversal.
    void inorder(TreeNode* root) {
        if (!root)
            return;
        inorder(root->left);
        // Check if we found a mismatched value.
        if (prev && prev->val > root->val) {
            // Check if 'first' is NULL.
            if (!first)
                first = prev;
            last = root;
        }
        prev = root;
        inorder(root->right);
    }
};