class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // Edge case: When the obstacle is placed at the starting position.
        if (obstacleGrid[0][0] == 1)
            return 0;
        // Mark the starting point as visited.
        obstacleGrid[0][0] = 1;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        // Start moving right.
        for (int i = 1; i < m; i++)
            obstacleGrid[i][0] = (obstacleGrid[i][0] == 0 && obstacleGrid[i-1][0] == 1) ? 1 : 0;
        // Start moving down.
        for (int j = 1; j < n; j++)
            obstacleGrid[0][j] = (obstacleGrid[0][j] == 0 && obstacleGrid[0][j-1] == 1) ? 1 : 0;
        // Check dynamically how many ways are there to visit each cell.
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++)
                obstacleGrid[i][j] = (obstacleGrid[i][j] == 0) ? obstacleGrid[i-1][j] + obstacleGrid[i][j-1] : 0;
        }
        return obstacleGrid[m-1][n-1];
    }
};