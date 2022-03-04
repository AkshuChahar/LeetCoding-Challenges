class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        // Initialise an array to keep track of overflowing champagne.
        double dp[101][101] = {{0}};
        // The first glass has all the liquid poured.
        dp[0][0] = (double) poured;

        // Traverse till the required row and keep track of overflowing liquid.
        for (int i = 0; i <= query_row; i++) {
            for (int j = 0; j <= i; j++) {
                // If the glass holds more than 1 unit of champagne, we spilt them into glasses in next row.
                if (dp[i][j] >= 1) {
                    dp[i+1][j] += (dp[i][j] - 1.0) / 2.0;
                    dp[i+1][j+1] += (dp[i][j] - 1.0) / 2.0;
                    // Set the current glass to 1.
                    dp[i][j] = 1;
                }
            }
        }
        return dp[query_row][query_glass];
    }
};