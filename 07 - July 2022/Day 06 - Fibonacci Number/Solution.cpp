class Solution {
public:
    int fib(int n) {
        // Edge case: For 'n < 2'.
        if (n < 2)
            return n;
        // Initialise the dp vector and push 1 twice as the start of series.
        vector<int> dp;
        dp.push_back(0);
        dp.push_back(1);
        // Complete the series.
        for (int i = 2; i <= n; i++)
            dp.push_back(dp[i-1] + dp[i-2]);
        return dp[n];
    }
};