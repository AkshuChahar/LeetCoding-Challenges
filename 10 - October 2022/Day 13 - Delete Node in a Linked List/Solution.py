# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteNode(self, node):
        """
        :type node: ListNode
        :rtype: void Do not return anything, modify node in-place instead.
        """
        # Change the value of the current node.
        node.val = node.next.val
        # Delete the next node.
        temp = node.next
        node.next = node.next.next
        temp.next = None
        del(temp)