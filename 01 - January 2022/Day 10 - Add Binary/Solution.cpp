class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";                        // String to store the answer.
        int carry = 0, sum;                     // To keep track to carry and sum.
        int i = a.size() - 1, j = b.size() - 1; // We start adding from right to left.

        while (i >= 0 || j >= 0) {
            sum = carry;                        // Every time sum should be equal to 0 and then we add carry to it.

            sum += (i >= 0) ? a[i--] - '0' : 0; // Increment 'sum' and decrement 'i'.
            sum += (j >= 0) ? b[j--] - '0' : 0; // Increment 'sum' and decrement 'j'.

            ans = char(sum % 2 + '0') + ans;    // Append to answer at front to avoid reversing in the end.
            carry = sum / 2;                    // Update the carry.
        }

        if (carry)                              // If carry still remains add '1'.
            ans = '1' + ans;

        return ans;
    }
};