# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def maxAncestorDiff(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        # Function to get the maximum of left and right subtree.
        def helper(node, cur_max, cur_min):
            # Check if we have reached the end of the node.
            if not node:
                return cur_max - cur_min
            # Update 'curr_max' and 'curr_min'.
            cur_max = max(cur_max, node.val)
            cur_min = min(cur_min, node.val)
            # Recurse of both subtrees.
            left = helper(node.left, cur_max, cur_min)
            right = helper(node.right, cur_max, cur_min)
            return max(left, right)
        return helper(root, root.val, root.val)