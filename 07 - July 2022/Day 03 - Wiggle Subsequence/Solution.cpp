class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        // Edge case: If the length of array is less than 2, it is a wiggle subsequence.
        if (n < 2)
            return n;
        // Initialise a variable to keep track if the previous difference is +ve or -ve.
        int prev = nums[1] - nums[0];
        int ans = (prev != 0) ? 2 : 1;
        // Traverse the array.
        for (int i = 2; i < n; i++) {
            int diff = nums[i] - nums[i-1];
            // If there is a change in signs for the diff, update 'ans' and 'prev'.
            if ((diff > 0 && prev <= 0) || (diff < 0 && prev >= 0)) {
                ans++;
                prev = diff;
            }
        }
        return ans;
    }
};