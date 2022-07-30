class Solution {
public:
    // Helper function to calculate the frequency of each character in a string.
    vector<int> helper(string word) {
        // Initialise vector and store the frequencies.
        vector<int> freq(26, 0);
        for (char c:word)
            freq[c - 'a']++;
        return freq;
    }

    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        // Get the maximum frequency.
        vector<int> maxfreq(26, 0);
        for (string word:words2) {
            vector<int> freq = helper(word);
            for (int i = 0; i < 26; i++)
                maxfreq[i] = max(freq[i], maxfreq[i]);
        }
        // Check if all the words in 'word1' have the character frequency more than or equal to the corresponding 'maxfreq'.
        for (string word:words1) {
            vector<int> freq = helper(word);
            bool flag = true;
            for (int i = 0; i < 26; i++) {
                if (freq[i] < maxfreq[i]) {
                    flag = false;
                    break;
                }
            }
            if (flag)
                ans.push_back(word);
        }
        return ans;
    }
};