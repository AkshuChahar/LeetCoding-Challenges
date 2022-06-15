class Solution {
public:
    // Function for sorting.
    static bool comp(const string& word1, const string& word2) {
        return word1.size() < word2.size();
    }

    int longestStrChain(vector<string>& words) {
        int ans = 1;
        // Sort the list of words according totheir size.
        sort(words.begin(), words.end(), comp);
        // Initialise a map for keeping track of the longest possible chain found ending with each word.
        unordered_map<string, int> m;
        // Traverse through the list of words.
        for (string word:words) {
            // Add the word to the map.
            m[word] = 1;
            // Check if we find the predecessor of the current word by removing any one of its characters.
            for (int i = 0; i < word.size(); i++) {
                string temp = word.substr(0, i) + word.substr(i + 1);
                if (m.find(temp) != m.end()) {
                    // Update the map and 'ans'.
                    m[word] = max(m[temp] + 1, m[word]);
                    ans = max(ans, m[word]);
                }
            }
        }
        return ans;
    }
};