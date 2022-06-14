class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        // Initialise a vector for tabulation.
        vector<int> dp(n+1, 0);
        // Check till 'i-th' character of the first word.
        for (int i = 0; i <= m; i++) {
            int prev;
            // Check till 'j-th' character of the second word
            for (int j = 0; j <= n; j++) {
                int temp = dp[j];
                // Check if we are at the start of any word.
                if (i == 0 || j == 0)
                    dp[j] = i + j;
                // Check if the current characters are same for both words.
                else if (word1[i-1] == word2[j-1])
                    dp[j] = prev;
                // Update the 'dp' vector.
                else
                    dp[j] = min(dp[j], dp[j-1]) + 1;
                prev = temp;
            }
        }
        return dp[n];
    }
};