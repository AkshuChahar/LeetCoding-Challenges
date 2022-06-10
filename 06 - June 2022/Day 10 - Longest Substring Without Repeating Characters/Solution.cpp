class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0, left = 0;
        // Initialise an array to keep track of the encountered characters.
        vector<int> ind(128);
        // Traverse the string and keep track of the maximum window size without repeating characters.
        for (int right = 0; right < s.size(); right++) {
            // Update 'ind'.
            ind[s[right]]++;
            // Repeat untill we get a window with non-repeating characters.
            while (ind[s[right]] > 1) {
                // Update 'ind' and move the 'left' pointer.
                ind[s[left]]--;
                left++;
            }
            // Update 'ans'.
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};