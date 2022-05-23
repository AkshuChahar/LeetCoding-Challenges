class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        // Initialise the dp vector.
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        // Traverse through the array.
        for (auto str:strs) {
            // Count the number of '0's' and '1's'.
            int zero = count(str.begin(), str.end(), '0');
            int one = str.size() - zero;
            // Update the 'dp' vector.
            for (int i = m; i >= zero; i--) {
                for (int j = n; j >= one; j--)
                    dp[i][j] = max(dp[i][j], 1 + dp[i - zero][j - one]);
            }
        }
        return dp[m][n];
    }
};