class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Here we use Boyer-Moore Algorithm (for Follow-up Question)
        // This basically eliminates equal number of minority and majority elements.
        // In the end, we are only left with majority element.

        // First, initialise a variable to keep track of current element's occurances.
        // We believe that this is the majority element.
        // Initialise a variable to keep track how many times the current element occurs.
        int count = 0, ans;

        for (int num:nums) {
            // When 'count' reaches 'zero', update 'ans'.
            ans = (count == 0) ? num : ans;
            // If 'num' == 'ans', increment 'count'. Else decrement it.
            count += (num == ans) ? 1 : -1;
        }

        return ans;
    }
};