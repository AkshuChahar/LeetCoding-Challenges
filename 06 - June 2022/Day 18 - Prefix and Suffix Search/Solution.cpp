class WordFilter {
public:
    // Initialise a map to store all the possible prefix and suffix strings.
    unordered_map<string, int> m;

    WordFilter(vector<string>& words) {
        int n = words.size();
        // Repeat for each word.
        for (int i = 0; i < n; i++) {
            int len = words[i].size();
            // Get all the prefix and suffix combinations.
            string pre = "";
            for (int j = 0; j <= len; j++) {
                string suf = "";
                for (int k = len - 1; k >= 0; k--) {
                    suf = words[i][k] + suf;
                    // Add the word to the map with the index.
                    m[suf + '{' + pre] = i;
                }
                pre += words[i][j];
            }
        }
    }

    int f(string prefix, string suffix) {
        return ((m.find(suffix + '{' + prefix) == m.end()) ? -1 : m[suffix + '{' + prefix]);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */