class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int M = 1000000000 + 7, count = 0;
        // Initialise the 'dp' vector and update the starting index.
        vector<vector<int>> dp(m, vector<int>(n));
        dp[startRow][startColumn] = 1;
        // CHeck for moves.
        for (int moves = 1; moves <= maxMove; moves++) {
            // Intialise a temporary vector to store the update 'dp' vector.
            vector<vector<int>> temp(m, vector<int>(n));
            // Traverse through the grid.
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    // Check for boundary conditions.
                    if (i == m - 1)
                        count = (count + dp[i][j]) % M;
                    if (j == n - 1)
                        count = (count + dp[i][j]) % M;
                    if (i == 0)
                        count = (count + dp[i][j]) % M;
                    if (j == 0)
                        count = (count + dp[i][j]) % M;
                    // Fill the temporary vector.
                    temp[i][j] = (((i > 0 ? dp[i - 1][j] : 0) + (i < m - 1 ? dp[i + 1][j] : 0)) % M + ((j > 0 ? dp[i][j - 1] : 0) + (j < n - 1 ? dp[i][j + 1] : 0)) % M) % M;
                }
            }
            // Update the 'dp' vector.
            dp = temp;
        }
        return count;
    }
};