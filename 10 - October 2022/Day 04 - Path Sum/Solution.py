# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        # Edge case: Check if we have reached the end of the path.
        if not root:
            return False
        # Check if we have reached the leaf node and the acquired the sum.
        if (not root.left) and (not root.right):
            if targetSum == root.val:
                return True
            return False
        # Check for next node.
        if self.hasPathSum(root.left, targetSum - root.val) or self.hasPathSum(root.right, targetSum - root.val):
            return True
        return False