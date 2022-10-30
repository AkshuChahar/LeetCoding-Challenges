class Solution:
    def shortestPath(self, grid: List[List[int]], k: int) -> int:
        m, n = len(grid), len(grid[0])
        # Check if we can use the path along the edges.
        if k >= m + n - 2:
            return m + n - 2
        # Initialise a queue for 'Breadth-First Search' and a set to keep track of visited cells.
        q = deque([(0, 0, k, 0)])
        visited = set()
        while q:
            row, col, rem, ans = q.popleft()
            # Check if we have reached the destination.
            if (row == m - 1) and (col == n - 1):
                return ans
            # Move in all directions while checking for obstacles.
            for x, y in [(row + 1, col), (row, col + 1), (row - 1, col), (row, col - 1)]:
                if (0 <= x < m) and (0 <= y < n) and (rem >= grid[x][y]):
                    res = (x, y, rem - grid[x][y], ans + 1)
                    if res[0:3] not in visited:
                        q.append(res)
                        visited.add(res[0:3])
        return -1