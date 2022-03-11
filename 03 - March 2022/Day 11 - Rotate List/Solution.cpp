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
    ListNode* rotateRight(ListNode* head, int k) {
        // Edge case: If no nodes or only one node is present.
        if (!head || !head->next)
            return head;

        // Go to the last node and find the length of list.
        int n = 1;
        ListNode *right = head;
        while (right->next) {
            n++;
            right = right->next;
        }
        // Point this to the head;
        right->next = head;

        // When 'k' is greater than 'n', update 'k'.
        k %= n;

        // Traverse again 'n-k' times to get the final tail.
        int count = 0;
        while (count < n - k) {
            right = right->next;
            count++;
        }

        // Make the next node 'head' and next of current node 'NULL'.
        head = right->next;
        right->next = NULL;

        return head;
    }
};