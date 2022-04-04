/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        // Initialise 3 pointers.
        ListNode *right = head, *left = head, *curr = head;
        // Move the 'curr' pointer to 'k-th' index.
        while (--k)
            curr = curr->next;
        // Mark the 'curr' node as the first node to be swapped.
        left = curr;
        // Now move 'curr' and 'right' untill 'curr' reaches the end.
        // This will give us the second node.
        while (curr->next) {
            curr = curr->next;
            right = right->next;
        }
        // Swap the values.
        swap(left->val, right->val);
        return head;
    }
};