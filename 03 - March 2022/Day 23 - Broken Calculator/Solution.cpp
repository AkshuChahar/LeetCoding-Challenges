class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int ans = 0;
        // Work backwards.
        while (target > startValue) {
            // Increment the count.
            ans++;
            // If 'target' is odd, increment it by 1. Also increment the count.
            if (target % 2 == 1) {
                target++;
                ans++;
            }
            // Half the target.
            target /= 2;
        }
        // We are now 'startValue - target' steps away from our solution.
        return ans + startValue - target;
    }
};