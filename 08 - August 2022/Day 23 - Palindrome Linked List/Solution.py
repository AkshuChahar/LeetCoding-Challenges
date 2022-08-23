# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        # Edge case: Check if there is only 1 node.
        if not head.next:
            return True
        # Initialise pointers to get to the middle of the linked list.
        slow, fast = head, head.next
        n = 0
        # Traverse the linked list.
        while fast and fast.next:
            slow, fast = slow.next, fast.next.next
            n += 1
        # Reverse the second half of the list.
        mid, prev = slow, None
        while mid:
            mid.next, mid, prev = prev, mid.next, mid
        # Check both lists.
        start, end = head, prev
        for _ in range(n + 1):
            if start.val != end.val:
                return False
            start, end = start.next, end.next
        return True