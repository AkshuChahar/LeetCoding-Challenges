# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def rangeSumBST(self, root: Optional[TreeNode], low: int, high: int) -> int:
        ans = 0
        # Initialise queue for 'Breadth-First Search'.
        q = deque()
        q.append(root)
        # Perform 'Breadth-First Search'.
        while q:
            n = len(q)
            while n:
                curr = q.popleft()
                # Update 'ans'.
                if low <= curr.val <= high:
                    ans += curr.val
                    if curr.left:
                        q.append(curr.left)
                    if curr.right:
                        q.append(curr.right)
                # Check for next node.
                elif low > curr.val and curr.right:
                    q.append(curr.right)
                elif high < curr.val and curr.left:
                    q.append(curr.left)
                n -= 1
        return ans