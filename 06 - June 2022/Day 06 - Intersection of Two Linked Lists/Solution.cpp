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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // Initialise two pointers, one for each linked list.
        ListNode *p1 = headA, *p2 = headB;
        // Traverse both lists untill both pointers point to the same node.
        while (p1 != p2) {
            // Whenever a pointer becomes NULL, initialise it to the head of other list.
            p1 = (!p1) ? headB : p1->next;
            p2 = (!p2) ? headA : p2->next;
        }
        return p1;
    }
};