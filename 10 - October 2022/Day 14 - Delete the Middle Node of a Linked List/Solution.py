# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # Edge case: Check if only one exists.
        if not head.next:
            return None
        # Initialise two pointers.
        slow, fast = head, head.next.next
        # Iterate till end.
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        # Check if the linked list has even length.
        if fast and fast.next:
            slow = slow.next
        # Delete the node.
        temp = slow.next
        slow.next = temp.next
        temp.next = None
        del(temp)
        return head