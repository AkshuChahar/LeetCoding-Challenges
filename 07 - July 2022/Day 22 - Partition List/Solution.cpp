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
    ListNode* partition(ListNode* head, int x) {
        // Intialise 2 'dummy' pointers to keep track of before and after values.
        ListNode* before_head = new ListNode(0), *after_head = new ListNode(0);
        ListNode* before = before_head, *after = after_head;
        // Traverse the original list.
        while (head) {
            // Check if the node belongs in 'before' part or the 'after' part.
            if (head->val < x) {
                before->next = head;
                before = before->next;
            }
            else {
                after->next = head;
                after = after->next;
            }
            head = head->next;
        }
        // Merge the lists.
        before->next = after_head->next;
        after->next = NULL;
        return before_head->next;
    }
};