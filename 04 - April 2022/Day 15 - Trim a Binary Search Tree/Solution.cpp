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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        // Check if we have reached a leaf node.
        if (!root)
            return root;
        // If the node value is less than 'low', we check the right sub-tree.
        if (root->val < low)
            return trimBST(root->right, low, high);
        // If the node value is greater than 'high', we check the left sub-tree.
        if (root->val > high)
            return trimBST(root->left, low, high);
        // If the value is in range, we check for both left and right sub-tree.
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }
};