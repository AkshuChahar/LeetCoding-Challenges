class Solution {
public:
    // Function for backtracking.
    void backtrack(string digits, int n, int start, vector<string>& ans, string& res, unordered_map<char, string>& m) {
        // If we have obtained a string of desired size, add it to 'ans'.
        if (res.size() == n) {
            ans.push_back(res);
            return;
        }

        // Iterate for all the digits.
        for (int i = start + 1; i < n; i++) {
            for (int j = 0; j < m[digits[i]].size(); j++) {
                // Add the corresponding letter to 'res'.
                res.push_back(m[digits[i]][j]);
                // Bactrack for next index.
                backtrack(digits, n, i, ans, res, m);
                res.pop_back();
            }
        }
    }

    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        // Edge case: If 'n' is 0, then we return an empty string.
        if (n == 0)
            return {};
        // Initialise a vector to store the final answer, a string to store the current combination and a map to match the digits with alphabets.
        vector<string> ans;
        string res = "";
        unordered_map<char, string> m;
        m['2'] = "abc";
        m['3'] = "def";
        m['4'] = "ghi";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz";
        // Call 'backtrack' for the current combination.
        backtrack(digits, n, -1, ans, res, m);
        return ans;
    }
};