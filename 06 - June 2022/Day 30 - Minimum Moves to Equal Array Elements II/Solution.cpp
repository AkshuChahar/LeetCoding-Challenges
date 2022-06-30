class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int ans = 0, n = nums.size();
        // Fix the median.
        nth_element(nums.begin(), nums.begin() + n/2, nums.end());
        int median = nums[n/2];
        // Traverse the array and calculate the difference of the current element and the median.
        for (int i = 0; i < n; i++)
            ans += abs(nums[i] - median);
        return ans;
    }
};