class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        m, n = len(heights),len(heights[0])
        ans = []
        # Initialise sets to store the cells we have already visited.
        pac, atl = set(), set()
        # Function for 'Breadth-First Search'.
        def bfs(visited, row, col):
            # Initialise a queue for traversal.
            q = collections.deque()
            q.append((row, col))
            while len(q) != 0:
                r, c = q.popleft()
                # Check if the cell is already visited.
                if (r, c) in visited:
                    continue
                visited.add((r, c))
                # Check if both the oceans can be reached from the current cell.
                if ((r, c) in pac) and ((r, c) in atl):
                    ans.append([r, c])
                # Check in all directions.
                if (r + 1 < m) and (heights[r + 1][c] >= heights[r][c]):
                    q.append((r + 1, c))
                if (c + 1 < n) and (heights[r][c + 1] >= heights[r][c]):
                    q.append((r, c + 1))
                if (r - 1 >= 0) and (heights[r - 1][c] >= heights[r][c]):
                    q.append((r - 1, c))
                if (c - 1 >= 0) and (heights[r][c - 1] >= heights[r][c]):
                    q.append((r, c - 1))
        # Check for top and bottom rows.
        for i in range(n):
            bfs(pac, 0, i)
            bfs(atl, m - 1, i)
        # Check for left and right columns.
        for i in range(m):
            bfs(pac, i, 0)
            bfs(atl, i, n - 1)
        return ans