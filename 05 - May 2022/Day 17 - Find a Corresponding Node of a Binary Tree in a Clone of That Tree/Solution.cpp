/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        // Here we will use Inorder Traversal to traverse both trees simultaneously.
        // Initialise stacks and pointers for traversal.
        stack<TreeNode*> s1, s2;
        TreeNode *n1 = original, *n2 = cloned;
        while (!s1.empty() || n1) {
            while (n1) {
                // Add the current nodes of both trees to the respective stacks.
                s1.push(n1);
                s2.push(n2);
                n1 = n1->left;
                n2 = n2->left;
            }
            n1 = s1.top(), n2 = s2.top();
            s1.pop(), s2.pop();
            // If we have reached the target node, we return the cloned node reference.
            // We compare the nodes itself, which takes care of duplicate values.
            if (n1 == target)
                return n2;
            n1 = n1->right;
            n2 = n2->right;
        }
        return NULL;
    }
};