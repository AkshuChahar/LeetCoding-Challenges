class Solution {
public:
    int splits(vector<int>& nums, int sum) {
        // Initialise variables to store the current sum and the splits required.
        int curr = 0, split = 0;
        // Traverse the array.
        for (int num:nums) {
            // Add the element to current split if it does not exceed the 'sum'.
            if (curr + num <= sum)
                curr += num;
            // Else, add a new split and reset the current sum.
            else {
                split++;
                curr = num;
            }
        }
        return split + 1;
    }

    int splitArray(vector<int>& nums, int m) {
        // Here we will be using 'Binary Search'.
        // Get the sum and maximum element of 'nums'.
        int sum = 0, largest = INT_MIN;
        for (int num:nums) {
            sum += num;
            largest = max(largest, num);
        }

        // Now, maximum element and sum becomes the left and right boundaries of our searchspace.
        int left = largest, right = sum;
        int ans = 0;
        // Do a 'Binary Search'.
        while (left <= right) {
            // 'mid' will represent the maximum allowed sum of a subarray.
            int mid = left + (right - left)/2;
            // Now we find the minimum splits required to get to the sum.
            // If they are less than or equal to 'm', we move in the left searchspace.
            if (splits(nums, mid) <= m) {
                right = mid - 1;
                ans = mid;
            }
            // Otherwise, we will move to right searchspace.
            else
                left = mid + 1;
        }
        return ans;
    }
};