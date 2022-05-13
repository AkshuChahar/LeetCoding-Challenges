/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        // Initialise three pointers 'curr', 'head', 'tail'.
        // 'curr' for current node, 'head' and 'tail' for first and last node of every level.
        Node* curr = root, * head = NULL, * tail = NULL;
        // Traverse the tree.
        while (curr) {
            // Check if the current node has left child.
            if (curr->left) {
                // If this is not the first child, point the next pointer of previous child to this.
                if (tail)
                    tail = tail->next = curr->left;
                // Else, make this the 'head' node.
                else
                    head = tail = curr->left;
            }
            // Check if the current node has right child.
            if (curr->right) {
                // If this is not the first child, point the next pointer of previous child to this.
                if (tail)
                    tail = tail->next = curr->right;
                // Else, make this the 'head' node.
                else
                    head = tail = curr->right;
            }
            // Move the current pointer using 'next' which has already been established.
            curr = curr->next;
            // When 'curr' reaches the end of a level, point it to the 'head'.
            if (!curr) {
                curr = head;
                // Make 'head' and 'tail' again 'NULL'.
                head = tail = NULL;
            }
        }
        return root;
    }
};