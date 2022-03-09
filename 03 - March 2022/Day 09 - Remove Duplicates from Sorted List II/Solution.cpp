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
    ListNode* deleteDuplicates(ListNode* head) {
        // Temporary node to get the head node of new node.
        ListNode* dummy = new ListNode(0, head);
        // Initialise a pointer at 'dummy'.
        ListNode* left = dummy;

        // Traverse the list using 'head' pointer.
        while (head) {
            // If the current node and next node have same value, we have to delete them.
            if (head->next && head->val == head->next->val) {
                // Move 'head' while the same value is encountered.
                while (head->next && head->val == head->next->val)
                    head = head->next;
                // The 'left' node now directly have 'head's next node' as its next node.
                left->next = head->next;
            }
            // If the current node does have same value as its next node, move 'left'.
            else
                left = left->next;
            // Move 'head'.
            head = head->next;
        }

        return dummy->next;
    }
};