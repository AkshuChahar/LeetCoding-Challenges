/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Check if 'root' is NULL or one of the nodes is the parent node.
        if (!root || root == p || root == q)
            return root;
        // Traverse the left subtree.
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        // Traverse the right subtree.
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        // If we are at leaf nodes, return the current node.
        return (!left) ? right : (!right) ? left : root;
    }
};