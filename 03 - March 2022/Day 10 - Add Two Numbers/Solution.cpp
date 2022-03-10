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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Linked List to store the ans;
        ListNode *dummy = new ListNode();
        // Pointers to first digits.
        ListNode *a = l1, *b = l2, *c = dummy;
        // Variable to store carry.
        int carry = 0;
        // Iterate while elements are left.
        while (a != NULL || b != NULL) {
            int res = carry;
            // If first list has elements left.
            if (a != NULL) {
                res += a->val;
                a = a->next;
            }
            // If second list has elements left.
            if (b != NULL) {
                res += b->val;
                b = b->next;
            }
            // Add the result to new list.
            c->next = new ListNode(res % 10);
            c = c->next;
            // Update 'carry'.
            carry = res / 10;
        }
        // If there is a 'carry', add a new node at the end.
        if (carry)
            c->next = new ListNode(carry);

        return dummy->next;
    }
};