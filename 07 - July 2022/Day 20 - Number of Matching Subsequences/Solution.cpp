class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int w = words.size(), n = s.size(), ans = 0;
        // Initialise a map to store the characters and the indices where they occur.
        unordered_map<char, vector<int>> m;
        for (int i = 0; i < n; i++)
            m[s[i]].push_back(i);
        // Traverse the array.
        for (int i = 0; i < w; i++) {
            // Initialise a variable to keep track of the index of previous word.
            int last = n;
            bool flag = true;
            for (int j = words[i].size() - 1; j >= 0; j--) {
                // Initialise a boolean to check if we get a match or not.
                bool match = false;
                for (int k = m[words[i][j]].size() - 1; k >= 0; k--) {
                    if (last > m[words[i][j]][k]) {
                        // Update 'match' and 'last'.
                        match = true;
                        last = m[words[i][j]][k];
                        break;
                    }
                }
                // Check if match was found.
                if (!match) {
                    flag = false;
                    break;
                }
            }
            if (flag)
                ans++;
        }
        return ans;
    }
};