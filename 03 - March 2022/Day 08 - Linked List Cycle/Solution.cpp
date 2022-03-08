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
    bool hasCycle(ListNode *head) {
        // Initialise 2 pointers to 'head'.
        ListNode *fast = head;
        ListNode *slow = head;

        // Traverse the linked list.
        while (fast != NULL && fast->next != NULL) {
            // Move one pointer by 1 step and the other by 2 steps.
            slow = slow->next;
            fast = fast->next->next;
            // If they meet, there is a cycle.
            if (fast == slow)
                return true;
        }

        // If they don't meet (or in other words, we encounter 'NULL'), there is no cycle.
        return false;
    }
};