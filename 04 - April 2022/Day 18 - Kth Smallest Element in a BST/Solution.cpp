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
    int kthSmallest(TreeNode* root, int k) {
        // Initialise a vector to store the inorder traversal of tree.
        vector<int> ans;
        // Initialise a stack and a pointer to root node.
        stack<TreeNode*> s;
        TreeNode *curr = root;
        // Do the Inorder traversal.
        while (curr || !s.empty()) {
            if (curr) {
                s.push(curr);
                curr = curr->left;
            }
            else {
                TreeNode *temp = s.top();
                s.pop();
                ans.push_back(temp->val);
                curr = temp->right;
            }
        }
        // Return the 'k-th' element.
        return ans[k-1];
    }
};