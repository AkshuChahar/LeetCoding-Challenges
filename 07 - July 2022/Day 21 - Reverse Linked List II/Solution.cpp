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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // Initialise a 'dummy' node to handle the edge case.
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        // Initialise a node to keep track of the starting node from where the reversal starts.
        ListNode* prev = dummy;
        // Move the 'prev' pointer to the starting position.
        for (int i = 0; i < left - 1; i++)
            prev = prev->next;
        // Initialise pointer for reversal.
        ListNode* curr = prev->next;
        for (int i = 0; i < right - left; i++) {
            ListNode* forw = curr->next;
            // Do the reversal.
            curr->next = forw->next;
            forw->next = prev->next;
            prev->next = forw;
        }
        return dummy->next;
    }
};