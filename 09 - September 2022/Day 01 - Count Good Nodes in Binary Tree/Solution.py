# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        ans = [0]
        # Edge case: Check if the 'root' node is NULL.
        if not root:
            return ans
        # Function for 'Depth-First Search'.
        def dfs(node, curr):
            # Check if we have reached the end of path.
            if not node:
                return
            # Check if the current node is good.
            if node.val >= curr:
                # Update 'ans' and 'curr'.
                ans[0] += 1
                curr = node.val
            dfs(node.left, curr)
            dfs(node.right, curr)
        dfs(root, root.val)
        return ans[0]