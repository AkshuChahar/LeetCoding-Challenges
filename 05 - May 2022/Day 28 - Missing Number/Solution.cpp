class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0, n = nums.size();
        // Calculate the actual sum of the series.
        int actual = n * (n+1)/2;
        // Traverse the array and calculate its sum.
        for (int i=0; i<n; i++)
            sum += nums[i];
        // Return the difference of the actual sum of series and sum of elements of the array.
        return actual-sum;
    }
};