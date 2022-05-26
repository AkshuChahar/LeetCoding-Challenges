class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        // Repeat untill 'n' becomes 0.
        while (n) {
            // Update 'n' using 'bitwise AND'.
            n = n & n-1;
            count++;
        }
        return count;
    }
};