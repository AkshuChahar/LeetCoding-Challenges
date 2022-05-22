class Solution {
public:
    int countSubstrings(string s) {
        // Logic: A substring from index 'i' to 'j' is a palindrome if 's[i] == s[j]' and the substring from 'i+1' to 'j-1' is a palindrome.
        int n = s.size(), ans = 0;
        // Initialise a boolean dp vector.
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        // Traverse through the string following the above logic.
        for (int len = 0; len < n; len++) {
            for (int i = 0, j = len; j < n; i++, j++) {
                if (s[i] == s[j] && (j - i < 2 || dp[i+1][j-1])) {
                    dp[i][j] = true;
                    ans++;
                }
            }
        }
        return ans;
    }
};