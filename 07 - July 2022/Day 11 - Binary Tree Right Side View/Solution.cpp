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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        // Edge case: When the 'root' is NULL.
        if (!root)
            return {};
        // Initialise queue for traversal.
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int s = q.size();
            while (s) {
                TreeNode* curr = q.front();
                q.pop();
                // If it is the rightmost node, add it to the answer.
                if (s == 1)
                    ans.push_back(curr->val);
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
                s--;
            }
        }
        return ans;
    }
};