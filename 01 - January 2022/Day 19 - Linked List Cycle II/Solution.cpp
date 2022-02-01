/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // We are using Floyd Cycle Detection.
        ListNode* slow = head;
        ListNode* fast = head;

        // Iterate while 'fast' does not reach NULL.
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            // If 'slow' and 'fast' points to same node, there is a cycle.
            if (slow == fast)
                break;
        }

        // Return NULL if no cycle is detected.
        if (!fast || !fast->next)
            return NULL;

        // To return the start of index, we move 'head' and either of 'fast' or 'slow' by 1 step untill they meet. This gives us start of cycle.
        while (head != slow) {
            head = head->next;
            slow = slow->next;
        }

        return slow;
    }
};