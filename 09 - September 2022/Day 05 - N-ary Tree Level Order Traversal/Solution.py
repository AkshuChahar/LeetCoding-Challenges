"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        ans = []
        # Edge case: Check if the 'root' node is NULL.
        if not root:
            return ans
        # Initialise a queue for 'Level Order Traversal'.
        q = deque()
        q.append(root)
        while q:
            temp = []
            n = len(q)
            for _ in range(n):
                node = q.popleft()
                # Add the value to 'temp'.
                temp.append(node.val)
                # Get all the children nodes of 'node'.
                for child in node.children:
                    q.append(child)
            # Update 'ans'.
            ans.append(temp)
        return ans