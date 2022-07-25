class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        // Initialise the pointers for 'Binary Search'.
        int start = 0, end = n - 1;
        int mid;
        vector<int> ans(2, -1);
        // Perform 'Binary Search'.
        while (start <= end) {
            mid = start + (end - start)/2;
            if (nums[mid] == target) {
                // Check for the first and last occurance.
                int i = mid, j = mid;
                while (i >= 0 && nums[i] == target)
                    i--;
                while (j < n && nums[j] == target)
                    j++;
                ans[0] = i+1;
                ans[1] = j-1;
                break;
            }
            else if (nums[mid] > target)
                end = mid - 1;
            else
                start = mid + 1;
        }
        return ans;
    }
};