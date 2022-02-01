class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // Edge case: If k== nums.size(), we return the array as it is.
        if (k == nums.size())
            return;
        // If 'k' is greater than the size of array, we take 'k' as the remainder of k/nums.size().
        if (k > nums.size())
            k %= nums.size();
        // Lets understand each step with example:
        // nums = [1,2,3,4,5,6,7], k=3.
        reverse(nums.begin(), nums.end()-k);
        // After step 1 : nums = [4,3,2,1,5,6,7].
        reverse(nums.end()-k, nums.end());
        // After step 2 : nums = [4,3,2,1,7,6,5].
        reverse(nums.begin(), nums.end());
        // After step 3 : nums = [5,6,7,1,2,3,4], which is the desired result.
    }
};