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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // If BST is empty, make 'val' the root node and return it.
        if (!root)
            return new TreeNode(val);

        TreeNode *curr = root;      // Initialize a current pointer.

        while(true) {               // Loop runs untill we find the insert position.
            // If 'val' is less than current node's value, we move to left sub-tree. Else we move to right sub-tree. 
            // If the left and right nodes respectively are NULL, we insert 'val'.
            if (curr->val > val) {
                if (curr->left)
                    curr = curr->left;
                else {
                    curr->left = new TreeNode(val);
                    break;
                }
            }

            else {
                if (curr->right)
                    curr = curr->right;
                else {
                    curr->right = new TreeNode(val);
                    break;
                }
            }
        }

        return root;
    }
};