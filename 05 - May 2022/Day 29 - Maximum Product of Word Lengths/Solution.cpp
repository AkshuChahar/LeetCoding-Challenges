class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size(), ans = 0;
        // Initialise a vector for storing the 'bitmasks' of each word.
        vector<int> mask(n, 0);
        // Traverse through the array of words.
        for (int i = 0; i < n; i++) {
            // Create the mask for the current word.
            for (int j = 0; j < words[i].size(); j++)
                mask[i] |= 1 << (words[i][j] - 'a');
            // Check if any of the previous words has a letter in common with the current word.
            for (int k = 0; k < i; k++) {
                // If no common letter is found, update 'ans'.
                if ((mask[i] & mask[k]) == 0)
                    ans = max(ans, (int)(words[i].size() * words[k].size()));
            }
        }
        return ans;
    }
};