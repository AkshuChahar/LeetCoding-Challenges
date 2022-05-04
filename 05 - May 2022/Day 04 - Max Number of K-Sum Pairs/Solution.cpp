class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0;
        // Initialise a map to store the frequency of each element.
        unordered_map<int, int> m;
        // Traverse the array.
        for (int num:nums) {
            // Check if 'k - num' is present in the map.
            if (m[k - num] > 0) {
                // Update 'ans' and map.
                ans++; 
                m[k - num]--;
            }
            // Else add the element to the map.
            else
                m[num]++;
        }
        return ans;
    }
};