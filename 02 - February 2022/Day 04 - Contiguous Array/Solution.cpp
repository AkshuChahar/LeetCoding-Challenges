class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int ans = 0;

        // We will use a map to store the 'count' (number of 1's - number of 0's) and the index at which that 'count' was encountered first.
        // This will help us determine the length of current subarray.
        int count = 0;
        unordered_map<int, int> m;
        // Initially we store 'count' = 0 and index = -1.
        m[0] = -1;

        for (int i = 0; i < nums.size(); i++) {
            // Update 'count'.
            count += (nums[i] == 1) ? 1 : -1;
            // If we encounter the same 'count' again, it means that there is a subarray with equal number 
            // of 0's and 1's between the current index and the index it was encountered at first.
            // At every step we subtract the index of first occurance of this 'count' and current index to get the maximum length of the subarray.
            if (m.find(count) != m.end())
                ans = max(ans, i-m[count]);
            // If 'count' is encountered for the first time, add it to the map.
            else
                m[count] = i;
        }

        return ans;
    }
};