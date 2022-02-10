class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;

        // Initialise a map to store the cumulative sums and their frequencies.
        unordered_map<int, int> m;
        // Initial sum=0 and frequency is 1.
        int sum = 0;
        m[sum]++;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            // If 'sum - k' exists, add its frequency to the 'ans'.
            if (m.find(sum - k) != m.end())
                ans += m[sum - k];
            // Increment the frequency of current sum.
            m[sum]++;
        }

        return ans;
    }
};