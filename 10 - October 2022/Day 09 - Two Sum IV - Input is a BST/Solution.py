# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def findTarget(self, root: Optional[TreeNode], k: int) -> bool:
        # Initialise a dictionary to store the elements and queue for traversal of the tree.
        d = defaultdict()
        q = deque()
        q.append(root)
        while len(q):
            n = len(q)
            while n:
                node = q.popleft()
                # Check if we got the required sum.
                if d.get(k - node.val):
                    return True
                d[node.val] = 1
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
                n -= 1
        return False