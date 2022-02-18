class Solution {
public:
    string removeKdigits(string num, int k) {
        // Edge case: When the number of digits to be removed equals the length of string.
        if (k == num.size())
            return "0";

        // We will use a string as stack.
        string ans = "";
        for (char c:num) {
            // Keep popping elements from stack while the current element is smaller than them and 'k' > 0.
            while (ans.size() && ans.back() > c && k) {
                ans.pop_back();
                k--;
            }
            // If the current element is not '0' or stack is not empty, add it to the stack.
            // This takes care of leading zeros.
            if (ans.size() || c != '0')
                ans.push_back(c);
        }
        // If 'k' is greater than 0, then remove the elements from the back.
        while (ans.size() && k--)
            ans.pop_back();

        return (ans == "") ? "0" : ans;
    }
};