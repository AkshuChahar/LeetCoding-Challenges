class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        n = len(graph)
        ans = []
        # Initialise a queue to traverse the graph.
        q = deque()
        for child in graph[0]:
            q.append((child, [0]))
        # Traverse the graph.
        while q:
            curr, path = q.popleft()
            # Check if we have reached the end of the path.
            if curr == n - 1:
                ans.append(path + [curr])
            # Update queue.
            for child in graph[curr]:
                q.append((child, path + [curr]))
        return ans