class Solution {
public:
    int divide(int dividend, int divisor) {
        // Edge case.
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        // Get the absolute values of dividend and divisor and get the final sign of answer.
        long dvd = labs(dividend), dvs = labs(divisor), ans = 0;
        int sign = ((dividend > 0) ^ (divisor > 0)) ? -1 : 1;
        // Repeat untill 'dvd >= dvs'.
        while (dvd >= dvs) {
            long temp = dvs, count = 1;
            // Left shift the temporary divisor.
            while (temp << 1 <= dvd) {
                // Update 'temp' and 'count'.
                temp <<= 1;
                count <<= 1;
            }
            // Update 'dvd' and 'ans'.
            dvd -= temp;
            ans += count;
        }
        return sign*ans;
    }
};