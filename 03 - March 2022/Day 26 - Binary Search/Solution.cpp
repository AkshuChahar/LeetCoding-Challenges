class Solution {
public:
    int search(vector<int>& nums, int target) {
        // Initialise a range with 2 pointers.
        int low = 0, high = nums.size()-1;

        // Traverse till the two pointers do not cross.
        while(low <= high) {
            // Find the middle of the range.
            int mid = low + (high - low) / 2;
            // If the required number is at the middle, return it.
            if (nums[mid] == target)
                return mid;
            // If the required number is greater than the middle number, search in the right half.
            else if (nums[mid] < target)
                low = mid + 1;
            // If the required number is less than the middle number, search in the left half.
            else
                high = mid - 1;
        }

        // If number is not found.
        return -1;
    }
};