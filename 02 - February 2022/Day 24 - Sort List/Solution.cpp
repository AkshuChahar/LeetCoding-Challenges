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
    // Initiate two lists to keep track of the previous sorted sublist and next sublist to be sorted.
    ListNode* prevSub = new ListNode(),* nextSub = new ListNode();

    ListNode* sortList(ListNode* head) {
        // Edge case: If list is empty or have only one element.
        if (!head || !head->next)
            return head;

        // Get the number of nodes in list.
        int n = 0;
        ListNode* temp = head;
        while (temp) {
            temp = temp->next;
            n++;
        }

        // Pointer to the start of sublist to be split.
        ListNode* start = head;
        ListNode dummy(0);
        // Split and merge the list into sizes = 1,2,4,.... < n.
        for (int size = 1; size < n; size *= 2) {
            // At every iteration tail points to dummy.
            prevSub = &dummy;
            while (start) {
                // If we reach the end for odd 'n', 'tail' just points to last node.
                if (!start->next) {
                    prevSub->next = start;
                    break;
                }
                // Split the list and get the mid.
                ListNode* mid = split(start, size);
                // Merge the sublists.
                merge(start, mid);
                // 'start' now points to next sublist.
                start = nextSub;
            }
            // 'start' points to 'dummy->next' at every iteration.
            start = dummy.next;
        }
        return dummy.next;
    }

    // Helper function for splitting.
    ListNode* split(ListNode* start, int size) {
        // Use slow and fast pointer approach to get the 'mid' of sublist.
        ListNode* mid1 = start;
        ListNode* end = start->next;

        for (int i = 1; i < size && (mid1->next || end->next); i++) {
            if (end->next)
                end = (end->next->next) ? end->next->next : end->next;
            mid1 = mid1->next;
        }

        // 'mid1->next' and 'end->next' gives us the 'mid' of current sub-list and 'start' of next sub-list respectively.
        ListNode* mid = mid1->next;
        nextSub = end->next;
        // Split the list.
        mid1->next = NULL;
        end->next = NULL;

        return mid;
    }

    // Helper function for merging.
    void merge(ListNode* start, ListNode* mid) {
        ListNode dum(0);
        ListNode* prev = &dum;
        // Compare the lists.
        while (start && mid) {
            if (start->val < mid->val) {
                prev->next = start;
                start = start->next;
                prev = prev->next;
            }
            else {
                prev->next = mid;
                mid = mid->next;
                prev = prev->next;
            }
        }
        // If one of the lists is exhausted, traverse the other list.
        prev->next = (start) ? start : mid;
        while (prev->next)
            prev = prev->next;

        // Link the 'prevSub' with the head of new list.
        prevSub->next = dum.next;
        prevSub = prev;
    }
};