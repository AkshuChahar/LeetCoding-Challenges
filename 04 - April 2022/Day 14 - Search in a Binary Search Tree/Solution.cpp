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
    TreeNode* searchBST(TreeNode* root, int val) {
        // Edge case: If 'root' is NULL.
        if (!root)
            return NULL;
        // Traverse the tree.
        while (root) {
            // Check if the current node is the required node.
            if (root->val == val)
                return root;
            // Check if the current node value is greater than the required value.
            // Move to the left subtree if that is the case.
            if (val < root->val && root->left)
                root = root->left;
            // If not, move to the right subtree.
            else if (val > root->val && root->right)
                root = root->right;
            // Break the loop if the node is not found.
            else
                break;
        }
        return NULL;
    }
};