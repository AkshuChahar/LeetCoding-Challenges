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
    // Helper function to merge two lists.
    ListNode* merge2lists(ListNode* l1, ListNode* l2) {
        if (!l1)
            return l2;
        if (!l2)
            return l1;

        ListNode* head = new ListNode(0);
        ListNode* curr = head;

        while (l1 != NULL && l2 != NULL) {
            if (l1->val <= l2->val) {
                curr->next = l1;
                curr = curr->next;
                l1 = l1->next;
            }
            else {
                curr->next = l2;
                curr = curr->next;
                l2 = l2->next;
            }
        }

        if (l1 == NULL)
            curr->next = l2;
        if (l2 == NULL)
            curr->next = l1;

        return head->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Edge case: If there are no lists.
        if (lists.size() == 0) 
            return NULL;

        // Now we will apply 'Divide and Conquer'.
        // We will divide the lists in pairs and merge them.
        // Then we will merge the pairs of the result of above step and keep doing that untill we get the result at 0th position.

        // Initial interval length = 1.
        int interval = 1;

        while (interval < lists.size()) {
            for (int i = 0; i + interval < lists.size(); i = i + interval * 2)
                lists[i] = merge2lists(lists[i], lists[i+interval]);
            interval *= 2;
        }

        return lists[0];
    }
};