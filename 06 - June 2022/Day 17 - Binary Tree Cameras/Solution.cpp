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
    // Unwatched - 0.
    // Watched with camera - 1.
    // Watched without camera - 2.
    int ans;

    // Function for DFS.
    int dfs(TreeNode* node) {
        if (!node)
            return 2;
        // Get the cameras required for the left subtree and right subtree.
        int left = dfs(node->left), right = dfs(node->right);
        // If any of the child nodes are not watched, we need to place a camera at the current node.
        if (left == 0 || right == 0) {
            ans++;
            return 1;
        }
        // If any of the nodes are watched with camera, we dont need to place a camera at the current node.
        return (left == 1 || right == 1) ? 2 : 0;
    }

    int minCameraCover(TreeNode* root) {
        // Check if the root node is watched or not.
        return ((dfs(root) < 1) ? 1 : 0) + ans;
    }
};