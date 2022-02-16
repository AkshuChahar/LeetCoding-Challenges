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
    ListNode* swapPairs(ListNode* head) {
        // If 'head' is NULL, return NULL.
        if (!head)
            return NULL;

        // Initialise two nodes and change the head to second node of the list while swapping.
        ListNode* l1 = head;
        ListNode* l2 = head;
        if (l1->next) {
            head = l1->next;
            l2 = head->next;
            head->next = l1;
            l1->next = l2; 
        }

        // Now do the same as above with the help of a temporary node.
        ListNode* temp;
        while (l2 && l2->next) {
            temp = l2->next->next;
            l1->next = l2->next;
            l1->next->next = l2;
            l1 = l2;
            l2->next = temp;
            l2 = l2->next;
        }

        return head;
    }
};