/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // Edge case: If list is empty.
        if (!head)
            return head;

        // Interweave the list with copies.
        Node *original = head;
        while (original) {
            // Make new node.
            Node *copy = new Node(original->val);
            copy->next = original->next;
            original->next = copy;
            original = copy->next;
        }

        original = head;
        // Set the random pointers of the copied elements.
        while (original) {
            original->next->random = (original->random) ? original->random->next : NULL;
            original = original->next->next;
        }

        // Unweave the original and copied list.
        original = head;
        Node *copied = head->next;
        Node *ans = head->next;
        while (original) {
            original->next = original->next->next;
            copied->next = (copied->next) ? copied->next->next : NULL;

            original = original->next;
            copied = copied->next;
        }

        return ans;
    }
};