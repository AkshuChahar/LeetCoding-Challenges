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

class BSTIterator {
public:
    // Initialise a stack for traversal.
    stack<TreeNode*> s;

    BSTIterator(TreeNode* root) {
        // Call the function for traversal.
        traversal(root);
    }

    // Function for traversal.
    void traversal(TreeNode* root) {
        // Get to the leftmost node.
        while (root) {
            s.push(root);
            root = root->left;
        }
    }

    int next() {
        // Return the current node and move to right subtree.
        TreeNode *curr = s.top();
        s.pop();
        traversal(curr->right);
        return curr->val;
    }

    bool hasNext() {
        // Return 'false' if we have finished the traversal.
        return !s.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */