# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        # Initialise two pointers for traversal.
        slow, fast = head, head
        # Move the 'fast' ahead by n steps.
        while n and fast:
            fast = fast.next
            n -= 1
        # Check if we have reached the end of the linked list.
        if not fast:
            return head.next
        # Move the 'slow' and 'fast' pointers untill 'fast' reaches the end of list.
        while fast.next:
            slow = slow.next
            fast = fast.next
        # Delete the node ahead of 'slow'.
        slow.next = slow.next.next
        return head