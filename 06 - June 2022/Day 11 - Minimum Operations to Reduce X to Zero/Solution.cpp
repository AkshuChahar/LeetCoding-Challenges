class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size(), sum = accumulate(nums.begin(), nums.end(), 0);
        // We need to find out a sub-array with sum equal to 'sum - x'.
        int target = sum - x;
        // We will be using 'Sliding Window Approach'.
        int res = 0, left = 0, ans = 0;
        bool found = false;
        // Traverse the array.
        for (int right = 0; right < n; right++) {
            // Update 'res'.
            res += nums[right];
            // Update the window if the current sum exceeds the required amount.
            while (left <= right && res > target) {
                res -= nums[left];
                left++;
            }
            // Update 'ans' if we get the required sum.
            if (res == target) {
                found = true;
                ans = max(ans, right - left + 1);
            }
        }
        return found ? n - ans : -1;
    }
};