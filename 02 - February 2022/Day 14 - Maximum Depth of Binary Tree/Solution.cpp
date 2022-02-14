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
    int maxDepth(TreeNode* root) {
        // Perform a BFS and count the levels.
        // Edge case: If 'root' is NULL.
        if (!root)
            return 0;

        // Initialise a queue, push 'root' node and initialise a variable to store height.
        queue<TreeNode*> q;
        q.push(root);
        int depth=0;

        while(!q.empty()) {
            // Increment 'depth'.
            depth++;
            int i = q.size();

            while(i>0) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left!=NULL)
                    q.push(node->left);
                if (node->right!=NULL)
                    q.push(node->right);
                i--;
            }
        }

        return depth;
    }
};