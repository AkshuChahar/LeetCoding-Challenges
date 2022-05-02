class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        // Initialise two pointers.
        int left = 0, right = nums.size() - 1;
        // Traverse the array.
        while (left < right) {
            // If the left integer is odd and right integer is even, we swap them.
            if (nums[left] % 2 > nums[right] % 2)
                swap(nums[left], nums[right]);
            // If the left integer is even, we move the pointer by 1 step.
            if (nums[left] % 2 == 0)
                left++;
            // If the right integer is odd, we move the pointer by 1 step.
            if (nums[right] % 2 == 1)
                right--;
        }
        return nums;
    }
};