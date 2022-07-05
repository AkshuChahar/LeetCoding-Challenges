class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        // Initialise a set and store the numbers in it.
        unordered_set<int> s;
        for (int num:nums)
            s.insert(num);
        // Now traverse the set.
        for (int num:s) {
            // Check if the current number is the beginning of a sequence.
            if (s.find(num - 1) == s.end()) {
                // Start a new sequence.
                int curr = num, res = 1;
                // Continue checking for next numbers in the sequence.
                while (s.find(curr + 1) != s.end()) {
                    // Update 'curr' and 'res'.
                    curr += 1;
                    res++;
                }
                // Update 'ans'.
                ans = max(ans, res);
            }
        }
        return ans;
    }
};