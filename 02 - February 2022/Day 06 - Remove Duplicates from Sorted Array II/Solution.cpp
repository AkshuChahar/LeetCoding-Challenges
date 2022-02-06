class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Initialise 2 pointers.
        int left = 0, right = 0;

        // Start traversing the array.
        while (right < nums.size()) {
            // The 'right' points at the 1st occurance of an element. So make the element at 'left' equal to element at 'right'.
            // This is the first occurance of the element in final array. Increment both pointers.
            nums[left++] = nums[right++];

            // Initialise a 'count' variable to count the occurances of the current element.
            int count = 0;
            while (right < nums.size() && nums[right] == nums[left-1]) {
                right++;
                count++;
            }

            // If more than one occurances of the element is encountered, set the element at 'left' pointer equal to current element.
            if (count)
                nums[left++] = nums[right-1];
        }

        return left;
    }
};