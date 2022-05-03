class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        // Initialise two pointers to keep track of start and end points.
        int left = 0, right = 0;
        // Initialise two variables to keep track of maximum and minimum values encountered while traversing.
        int max_seen = INT_MIN, min_seen = INT_MAX;
        // Move from start to end of 'nums' and keep track of elements out-of-order.
        for (int i = 0; i < n; i++) {
            // If the current value is less than 'max_seen', update 'max_seen' and 'right'.
            max_seen = max(nums[i], max_seen);
            if (nums[i] < max_seen)
                right = i;
        }
        // Move from end to start of 'nums' and keep track of elements out-of-order.
        for (int i = n - 1; i >= 0; i--) {
            // If the current value is more than 'min_seen', update 'min_seen' and 'left'.
            min_seen = min(nums[i], min_seen);
            if (nums[i] > min_seen)
                left = i;
        }
        // If 'right' is more than 0, it means we have found a sub-array.
        return (right > 0) ? right - left + 1 : 0;
    }
};