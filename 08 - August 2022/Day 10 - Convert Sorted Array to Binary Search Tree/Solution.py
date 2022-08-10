# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        n = len(nums)
        # Check if we have exhausted the nodes.
        if not n:
            return None
        # Find the middle element.
        mid = n//2
        # Recursively call the function on the left and right subarray after creating the node.
        return TreeNode(nums[mid], self.sortedArrayToBST(nums[:mid]), self.sortedArrayToBST(nums[mid + 1:]))