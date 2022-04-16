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
    TreeNode* convertBST(TreeNode* root) {
        // Initialise a stack for traversal and a variable to store the required sum.
        int sum = 0;
        stack<TreeNode*> s;
        TreeNode* curr = root;

        // Traverse the tree.
        while (!s.empty() || curr) {
            // Move to the rightmost node of the right subtree of current node.
            while (curr) {
                // Push it into the stack.
                s.push(curr);
                curr = curr->right;
            }
            // Add the node value to 'sum' and update tree.
            curr = s.top();
            s.pop();
            sum += curr->val;
            curr->val = sum;
            // Now move to the left subtree.
            curr = curr->left;
        }
        return root;
    }
};