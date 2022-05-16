class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        // Edge case: If the start or end of the matrix contains '1'.
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;
        // Edge case: If matrix contains only 1 cell.
        if (n == 1)
            return (grid[0][0]) ? -1 : 1;
        // Initialise the answer to 2 (start and end steps).
        int ans = 2;
        // Initialise a queue for BFS.
        queue<pair<int, int>> q;
        q.push(make_pair(0, 0));
        // Mark the start point as 'visited'.
        grid[0][0] = 1;
        while (!q.empty()) {
            int len = q.size();
            while (len--) {
                int r = q.front().first, c = q.front().second;
                q.pop();
                // Check for all directions.
                for (int i = max(0, r-1), m_i = min(r+1, n-1); i <= m_i; i++) {
                    for (int j = max(0, c-1), m_j = min(c+1, n-1); j <= m_j; j++) {
                        // Return if we have reached the end.
                        if (i == n-1 && j == n-1)
                            return ans;
                        if (grid[i][j] == 0) {
                            grid[i][j] = 1;
                            q.push(make_pair(i, j));
                        }  
                    }
                }
            }
            // Increment step.
            ans++;
        }
        return -1;
    }
};