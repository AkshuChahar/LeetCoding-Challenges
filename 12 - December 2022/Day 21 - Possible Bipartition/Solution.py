class Solution:
    def possibleBipartition(self, n: int, dislikes: List[List[int]]) -> bool:
        # Function for 'BFS'.
        def bfs(source):
            q = deque([source])
            # Start with marking source as 'RED'.
            color[source] = 0 
            while q:
                node = q.popleft()
                for neighbor in adj[node]:
                    # If there is a conflict, return False.
                    if color[neighbor] == color[node]: return False
                    if color[neighbor] == -1:
                        color[neighbor] = 1 - color[node]
                        q.append(neighbor)
            return True
        # Build the adjacency graph.
        adj = [[] for _ in range(n + 1)]
        for dislike in dislikes:
            adj[dislike[0]].append(dislike[1])
            adj[dislike[1]].append(dislike[0])
        # Mark red as 0 and blue as 1.
        color = [-1] * (n + 1)
        # Traverse the graph.
        for i in range(1, n + 1):
            if color[i] == -1:
                # For each pending component, run BFS.
                if not bfs(i):
                    return False
        return True