# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def oddEvenList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head:
            return None
        # Initialise pointers to mark the odd and even nodes and the first even node.
        even, odd, even_head = head.next, head, head.next
        # Traverse the Linked List.
        while (even and even.next):
            # Reorder the list.
            odd.next = even.next
            odd = even.next
            even.next = odd.next
            even = even.next
        # Re-attach the list.
        odd.next = even_head
        return head