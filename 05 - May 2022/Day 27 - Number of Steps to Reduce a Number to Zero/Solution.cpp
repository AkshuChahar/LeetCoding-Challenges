class Solution {
public:
    int numberOfSteps(int num) {
        int ans = 0;
        // Repeat untill 'num' becomes 0.
        while (num) {
            // We will use 'Bit-Manipulation'.
            // If 'num' is even, right shift by 1 or else we subtract 1.
            num = (num & 1) ? num - 1 : num >> 1;
            ans++;
        }
        return ans;
    }
};