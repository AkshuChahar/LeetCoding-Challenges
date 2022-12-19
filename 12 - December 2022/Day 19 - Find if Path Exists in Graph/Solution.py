class Solution:
    def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        # Initialise a list to keep track of visited nodes and a stack.
        seen = [False] * n
        seen[source] = True
        s = [source]
        # Store all edges according to nodes in 'graph'.
        graph = collections.defaultdict(list)
        for a, b in edges:
            graph[a].append(b)
            graph[b].append(a)
        # Traverse the graph.
        while s:
            curr_node = s.pop()
            # Add all unvisited neighbors of the current node to stack and mark them as visited.
            for next_node in graph[curr_node]:
                if next_node == destination:
                    return True
                if not seen[next_node]:
                    seen[next_node] = True
                    s.append(next_node)   
        return seen[destination]