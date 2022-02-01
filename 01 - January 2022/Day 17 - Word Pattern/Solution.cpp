class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> m1;
        unordered_map<string, char> m2;

        // Store all the words in a vector.
        vector<string> words;
        string word = "";
        for(int i=0; i<s.size(); i++) {
            // Add 'word' to vector whenever whitespace is encountered and set 'word' to "".
            if (s[i] == ' ') {
                words.push_back(word);
                word = "";
            }
            else
                word += s[i];
        }
        words.push_back(word);  // Add the last word to vector.

        // Check if numbers of words matches pattern size.
        if (words.size() != pattern.size())
            return false;

        for (int i=0; i<words.size(); i++) {
            // Add the pattern:word and word:pattern if not found in map.
            if (m1.find(pattern[i]) == m1.end()) {
                // If word:pattern already exists return 'false'.
                if (m2.find(words[i]) != m2.end())
                    return false;
                m1[pattern[i]] = words[i];
                m2[words[i]] = pattern[i];
            }

            // If pattern is already present, check if it has the same value.
            else {
                if (m1[pattern[i]] != words[i])
                    return false;
            }
        }

        return true;
    }
};