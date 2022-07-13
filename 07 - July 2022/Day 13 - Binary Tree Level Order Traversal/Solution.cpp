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
/*

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        // Edge case: If the 'root' node is NULL.
        if (!root)
            return ans;
        // Initialise the queue to keeping track of nodes and push the 'root' node in it.
        queue<TreeNode*> q;
        q.push(root);
        // Initialise a pointer for keeping track of the current node.
        TreeNode* curr = NULL;
        // Repeat untill we have visited all nodes.
        while (!q.empty()) {
            vector<int> n;
            // Get the current size of the queue.
            int count = q.size();
            // The current queue has the nodes of the current level.
            while (count > 0) {
                // For each node of the current level, add the value to answer and push its child nodes in the queue.
                curr = q.front();
                n.push_back(curr->val);
                q.pop();
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
                count--;
            }
            ans.push_back(n);
        }
        return ans;
    }
};