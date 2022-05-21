class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // Increment the amount by 1 for easier indexing.
        amount++;
        // Initialise an array for 'Tabulation'.
        int dp[amount];
        dp[0] = 0;
        // Find the least number of coins required for every amount.
        for (int i = 1; i < amount; i++) {
            dp[i] = INT_MAX;
            for (int j = 0; j < n; j++) {
                // Update the table if we find a coin value in our required range.
                if (coins[j] <= i && dp[i - coins[j]] != INT_MAX)
                    dp[i] = min(dp[i], 1 + dp[i-coins[j]]);
            }
        }
        return (dp[amount-1] == INT_MAX) ? -1 : dp[amount-1];
    }
};