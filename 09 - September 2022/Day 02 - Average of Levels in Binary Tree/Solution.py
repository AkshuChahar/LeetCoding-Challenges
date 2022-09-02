# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def averageOfLevels(self, root: Optional[TreeNode]) -> List[float]:
        ans = []
        # Initialise a queue for 'Level Order Traversal'.
        q = collections.deque()
        q.append(root)
        # Do a 'Level Order Traversal'.
        while len(q) != 0:
            sum = 0
            n = len(q)
            temp = n
            while n != 0:
                node = q.popleft()
                # Update the sum of the level.
                sum += node.val
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
                n -= 1
            # Add the average to the resulting array.
            ans.append(round(sum / temp, 5))
        return ans