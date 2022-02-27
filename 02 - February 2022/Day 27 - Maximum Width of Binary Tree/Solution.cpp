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
    int widthOfBinaryTree(TreeNode* root) {
        // The idea is to perform a BFS and keep count of the indices of the nodes.
        // For any level, the answer will be the distance between leftmost node and the left node of rightmost node of previous level.

        int ans = 0;
        // Initialise a queue to store the node and their index.
        queue<pair<TreeNode*, unsigned long>> q;
        q.push(make_pair(root, (long)1));

        // Perform a BFS.
        while (!q.empty()) {
            // Current leftmost node index and current rightmost node index.
            int left = q.front().second, right = left;
            int n = q.size();
            while (n--) {
                TreeNode* temp = q.front().first;
                // This will make the indices of next level start from 0, hence avoiding overflow.
                right = q.front().second - left;
                q.pop();
                if (temp->left)
                    q.push(make_pair(temp->left, (long)2 * right));
                if (temp->right)
                    q.push(make_pair(temp->right, (long)2 * right + 1));
            }
            // Update maximum width.
            ans = max(ans, right + 1);
        }

        return ans;
    }
};