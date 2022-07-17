class Solution {
public:
    int kInversePairs(int n, int k) {
        int M = 1000000000 + 7;
        // Initialise the dp vector.
        vector<int> dp(k + 1);
        for (int i = 1; i <= n; i++) {
            // Initialise a temporary vecctor to store the new array.
            vector<int> temp(k + 1);
            temp[0] = 1;
            // Update the temporary vector.
            for (int j = 1; j <= k; j++) {
                int val = (dp[j] + M - ((j - i) >= 0 ? dp[j - i] : 0)) % M;
                temp[j] = (temp[j - 1] + val) % M;
            }
            // Update the 'dp' vector.
            dp = temp;
        }
        return ((dp[k] + M - (k > 0 ? dp[k - 1] : 0)) % M);
    }
};