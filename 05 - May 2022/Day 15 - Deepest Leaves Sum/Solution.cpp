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
    int deepestLeavesSum(TreeNode* root) {
        // Here we will use BFS.
        queue<TreeNode*> q;
        q.push(root);
        // Initialise a variable to store the sum of a level just been visited.
        int ans;
        while (!q.empty()) {
            int n = q.size();
            // Initialise 'ans' to 0.
            ans = 0;
            while (n) {
                TreeNode* curr = q.front();
                q.pop();
                // Add to 'ans'.
                int val = curr->val;
                ans += curr->val;
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
                n--;
            }
        }
        return ans;
    }
};