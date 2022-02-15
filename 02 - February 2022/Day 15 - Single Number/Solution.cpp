class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // Initialise 'ans' to the first element.
        int ans = nums[0];
        // Traverse the array and do current 'ans' XOR current element. 
        for (int i=1; i<nums.size(); i++)
            ans ^= nums[i];
        // In the end, only the single element remains. Return this.
        return ans;
    }
};