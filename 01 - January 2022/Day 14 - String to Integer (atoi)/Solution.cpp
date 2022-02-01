class Solution {
public:
    int myAtoi(string s) {
        // 'ans' stores the integer value, 'sign' stores the sign as -1 or +1 (by default it is positive) and 'i' stores the current index.
        int ans = 0, sign = 1, i = 0;
        int n = s.size();

        // Eliminate leading whitespaces.
        while (i < n && s[i] == ' ')
            i++;

        // Take the first sign for the final answer, if any.
        if (i < n && s[i] == '+') {
            sign = 1;
            i++;
        }
        else if (i < n && s[i] == '-') {
            sign = -1;
            i++;
        }

        // Read all the digital characters and update 'ans'.
        while (i < n && isdigit(s[i])) {
            int curr = s[i] - '0';

            // Check for overflow or underflow for current 'ans'. Return INT_MAX or INT_MIN as per sign in case there is overflow or underflow.
            if ((ans > INT_MAX / 10) || (ans == INT_MAX / 10 && curr > 7))
                return (sign == 1) ? INT_MAX : INT_MIN;

            // Else update 'ans'.
            ans = ans * 10 + curr;
            i++;
        }

        return sign*ans;
    }
};