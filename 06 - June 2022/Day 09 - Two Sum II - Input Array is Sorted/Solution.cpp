class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // Initialise 2 pointers, 1 at the beginning and 1 at the end of the array.
        int left = 0, right = numbers.size()-1;
        vector<int> ans(2);
        // Traverse the array.
        while (left < right) {
            // If the current sum is less than the required sum, move the 'left' pointer.
            if (numbers[left] + numbers[right] < target)
                left++;
            // If the current sum is greater than the required sum, move the 'right' pointer.
            else if (numbers[left] + numbers[right] > target)
                right--;
            // If we get the required sum, update 'ans'.
            else {
                ans[0] = left + 1;
                ans[1] = right + 1;
                break;
            }
        }
        return ans;
    }
};