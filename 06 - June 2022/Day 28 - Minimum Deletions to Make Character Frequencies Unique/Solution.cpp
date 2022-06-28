class Solution {
public:
    int minDeletions(string s) {
        // Initially, the maximum allowed frequency for a character is equal to the size of string.
        int allowed = s.size(), ans = 0;
        // Store the frequencies in an array and sort it in descending order.
        vector<int> freq(26, 0);
        for (char c:s)
            freq[c - 'a']++;
        sort(freq.begin(), freq.end(), greater<int>());
        // Traverse over the frequencies.
        for (int i = 0; i < 26 && freq[i] > 0; i++) {
            // Check if the current frequency is greater than the allowed frequency.
            if (freq[i] > allowed) {
                // Set it equal to the allowed frequency and add the number of deletions required.
                ans += freq[i] - allowed;
                freq[i] = allowed;
            }
            // Update the allowed frequency.
            allowed = max(0, freq[i] - 1);
        }
        return ans;
    }
};