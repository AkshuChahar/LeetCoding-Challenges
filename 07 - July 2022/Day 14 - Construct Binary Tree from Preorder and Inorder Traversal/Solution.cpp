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
    // Initialise a map to keep track of nodes and their position and a variable to keep track of 'root' node.
    unordered_map<int, int> m;
    int index;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        index = 0;
        // Build the map.
        for (int i = 0; i < inorder.size(); i++)
            m[inorder[i]] = i;
        return helper(preorder, 0, preorder.size()-1);
    }

    // Function to build the tree.
    TreeNode* helper(vector<int>& preorder, int low, int high) {
        if (low > high)
            return NULL;
        int val = preorder[index];
        index++;
        // Use recursion.
        TreeNode* root = new TreeNode(val);
        root->left = helper(preorder, low, m[val]-1);
        root->right = helper(preorder, m[val]+1, high);
        return root;
    }
};