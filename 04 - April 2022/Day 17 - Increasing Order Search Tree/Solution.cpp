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
    // Initialise a global pointer.
    TreeNode* curr;

    TreeNode* increasingBST(TreeNode* root) {
        // Initialise a new tree.
        TreeNode* ans = new TreeNode(0);
        // Point 'curr' to 'ans'.
        curr = ans;
        // Do Inorder traversal of the tree.
        inorder(root);
        return ans->right;
    }

    // Inorder traversal.
    void inorder(TreeNode* root) {
        if (!root)
            return;
        inorder(root->left);
        // Make the left node NULL.
        root->left = NULL;
        // Add the current node to the right of 'curr'.
        curr->right = root;
        // Move 'curr'.
        curr = root;
        inorder(root->right);
    }
};