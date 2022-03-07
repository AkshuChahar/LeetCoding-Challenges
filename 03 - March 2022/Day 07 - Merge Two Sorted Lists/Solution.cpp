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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // Initialise pointers to keep track of current nodes.
        ListNode *p1 = l1, *p2 = l2;
        // Dummy node to keep track of head of merged list.
        ListNode *dummy = new ListNode();
        // Pointer to current node of new node.
        ListNode *p3 = dummy;

        // Traverse the nodes.
        while (p1 != NULL && p2 != NULL) {
            // If the node of list1 is less than list2, add to the new list.
            if (p1->val < p2->val) {
                p3->next = p1;
                p1 = p1->next;
            }
            // Else add list2 element to new list.
            else {
                p3->next = p2;
                p2 = p2->next;
            }
            // Increment the pointer to new list.
            p3 = p3->next;
        }

        // Add the remaining list1 elements.
        while (p1 != NULL) {
            p3->next = p1;
            p1 = p1->next;
            p3 = p3->next;
        }
        // Add the remaining list2 elements.
        while (p2 != NULL) {
            p3->next = p2;
            p2 = p2->next;
            p3 = p3->next;
        }

        return dummy->next;
    }
};