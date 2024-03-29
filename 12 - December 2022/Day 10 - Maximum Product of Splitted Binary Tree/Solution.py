﻿# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def maxProduct(self, root: Optional[TreeNode]) -> int:
        res = []
        # Function for 'DFS'.
        def dfs(node):
            if not node:
                return 0
            ans = dfs(node.left) + dfs(node.right) + node.val
            res.append(ans)
            return ans
        dfs(root)
        # Get the required sum.
        total = max(res)
        return max(i * (total - i) for i in res) % (10**9 + 7)