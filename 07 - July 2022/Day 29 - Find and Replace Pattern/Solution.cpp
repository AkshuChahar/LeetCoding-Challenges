class Solution {
public:
    // Helper function to check if a word matches the pattern.
    bool helper(string word, string pattern, int n) {
        // Initialise two maps for mapping the characters.
        unordered_map<char, char> m1, m2;
        // Traverse the strings.
        for (int i = 0; i < n; i++) {
            // Forward mapping.
            if (m1.find(word[i]) == m1.end())
                m1[word[i]] = pattern[i];
            // Reverse mapping.
            if (m2.find(pattern[i]) == m2.end())
                m2[pattern[i]] = word[i];
            // Check if the mapping is not same.
            if (m1[word[i]] != pattern[i] || m2[pattern[i]] != word[i])
                return false;
        }
        return true;
    }

    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        int n = pattern.size();
        vector<string> ans;
        // Traverse the array.
        for (string word:words) {
            // Check if the word matches the pattern using the helper function.
            if (helper(word, pattern, n))
                ans.push_back(word);
        }
        return ans;
    }
};