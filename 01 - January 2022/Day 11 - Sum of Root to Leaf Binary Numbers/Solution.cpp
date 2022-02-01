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
    int sumRootToLeaf(TreeNode* root) {
        return sum(root, 0);      // Call the helper function to traverse and calculate sum.
    }

    int sum(TreeNode* root, int curr_sum) {
        if (!root)                // If the root node is NULL, return 0.
            return 0;

        // Convert binary to decimal and add the value to current sum. This conversion works from left to right instead of classic right to left.
        curr_sum = (curr_sum * 2) + root->val;

        // When we reach a leaf node, we traverse back to the node where right node is still there.
        if (!root->left && !root->right)
            return curr_sum;

        // Return the sum of all leaf nodes.
        return (sum(root->left, curr_sum) + sum(root->right, curr_sum));
    }
};