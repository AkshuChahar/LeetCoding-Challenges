class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int ans = 0;

        // We use a maps to store the numbers(we only need unique pairs) with their frequency.
        unordered_map<int, int> m;
        for (int num:nums) {
            // Edge case: When k == 0, we need the equal pairs only(once).
            if (k == 0) {
                if (m.find(num) != m.end() && m[num] == 1)
                    ans++;
                m[num]++;
            }
            // Check if it is the first occurance of 'num'.
            if (m.find(num) == m.end()) {
                // Check if 'num - k' or 'k + num' is present in the map.
                if (m.find(num - k) != m.end())
                    ans++;
                if (m.find(num + k) != m.end())
                    ans++;
                m[num]++;
            }
        }
        return ans;
    }
};