class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size(), n2 = s2.size(), m = s3.size();
        // Edge case: If the length third string is not equal to sum of length of 2 strings.
        if (m != n1 + n2)
            return false;
        // Initialise a dp array to keep track of interleaving strings.
        vector<bool> dp(n2 + 1, false);
        // Traverse the strings.
        for (int i = 0; i <= n1; i++) {
            for (int j = 0; j <= n2; j++) {
                // Mark the first entry in the dp array.
                if (i == 0 && j == 0)
                    dp[j] = true;
                // Check for case 'i == 0'.
                else if (i == 0)
                    dp[j] = dp[j - 1] && s2[j - 1] == s3[i + j - 1];
                // Check for case 'j == 0'.
                else if (j == 0)
                    dp[j] = dp[j] && s1[i - 1] == s3[i + j - 1];
                else
                    dp[j] = (dp[j - 1] && s2[j - 1] == s3[i + j - 1]) || (dp[j] && s1[i - 1] == s3[i + j - 1]);
            }
        }
        return dp[n2];
    }
};