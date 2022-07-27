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
    // Function to get the rightmost node.
    TreeNode* helper(TreeNode* root) {
        // Check if we have reached the rightmost node.
        if (root->right == NULL)
            return root;
        // Move to right subtree.
        return helper(root->right);
    }
    
    void flatten(TreeNode* root) {
        // Edge case: Check if the 'root' node is NULL.
        if (!root)
            return;
        // Initialise two pointers for updating the list.
        TreeNode* rightmost, *next;
        // Traverse the tree.
        while (root) {
            // Check if there is a left subtree.
            if (root->left) {
                // Rearrange the nodes.
                rightmost = helper(root->left);
                next = root->right;
                root->right = root->left;
                root->left = NULL;
                rightmost->right = next;
            }
            root = root->right;
        }
    }
};