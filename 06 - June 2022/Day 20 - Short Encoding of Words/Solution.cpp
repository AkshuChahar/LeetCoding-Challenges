class Solution {
public:
    // Function to sort the list according to the word sizes.
    static bool cmp(string& a, string& b) {
        return a.size() > b.size();
    }

    int minimumLengthEncoding(vector<string>& words) {
        string ans;
        // Sort the word list.
        sort(words.begin(), words.end(), cmp);
        // Traverse the list.
        for (auto word:words) {
            // Check if the current word is already a part of 'ans'.
            if (ans.find(word + "#") == string::npos)
                ans += word + "#";
        }
        return ans.size();
    }
};