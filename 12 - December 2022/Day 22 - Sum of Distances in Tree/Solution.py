class Solution:
    def sumOfDistancesInTree(self, n: int, edges: List[List[int]]) -> List[int]:
        count = [1] * n
        ans = [0] * n
        # Initialise a graph.
        graph = collections.defaultdict(set)
        for u, v in edges:
            graph[u].add(v)
            graph[v].add(u)
        # Function for 'DFS'.
        def dfs(node = 0, parent = None):
            # Traverse the graph.
            for child in graph[node]:
                if child != parent:
                    dfs(child, node)
                    count[node] += count[child]
                    ans[node] += ans[child] + count[child]
        # Function to update 'ans'.
        def dfs2(node = 0, parent = None):
            # Traverse the graph.
            for child in graph[node]:
                if child != parent:
                    ans[child] = ans[node] - count[child] + n - count[child]
                    dfs2(child, node)
        dfs()
        dfs2()
        return ans