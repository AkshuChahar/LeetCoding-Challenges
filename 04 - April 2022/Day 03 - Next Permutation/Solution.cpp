class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // Initialise a pointer to the end of array.
        int i = nums.size() - 1;
        // Iterate while the array is in decreasing order.
        while (i > 0 && nums[i] <= nums[i-1])
            i--;
        // If non-decreasing order is found.
        if (i > 0) {
            // Initialise a pointer to the end.
            int j = nums.size() - 1;
            // Iterate untill we get a digit less the digit at 'i-1'.
            while (nums[j] <= nums[i-1])
                j--;
            // Swap these values.
            swap(nums[i-1], nums[j]);
        }
        // Reverse the array from 'i-th' position to end.
        reverse(nums.begin()+i, nums.end());
    }
};