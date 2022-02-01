class Solution {
public:
    bool winnerSquareGame(int n) {
        // Initialise a 'dp' vector.
        vector<bool> dp(n+1);

        // We start checking from 1 and store the results in 'dp'.
        for (int i=1; i<=n; i++) {
            for (int j=1; j*j <= i; j++) {
                if (!dp[i - j*j]) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};